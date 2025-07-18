#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#define NUM_READERS 5
#define NUM_WRITERS 2

pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;
int              data   = 0;

void* reader_job(void* arg)
{
	int id = *(int*)arg;

    printf("Reader %d, trying get read lock\n", id);

    pthread_rwlock_rdlock(&rwlock);
    printf("Reader %d: got the rwlock read lock\n", id);

    sleep(2); // Simulate working
    printf("Reader %d: printf data - %d\n", id, data);

    pthread_rwlock_unlock(&rwlock);
    printf("Reader %d: unlock the read lock\n", id);

    return NULL;
}

void* writer_job(void* arg)
{
	int id = *(int*)arg;

    printf("Writer %d: Entered thread, trying get write lock\n", id);

    pthread_rwlock_wrlock(&rwlock);
    printf("Writer %d: got the rwlock write lock\n", id);

    sleep(2); // Simulate working
    data++;
	printf("Writer %d: new data - %d\n", id, data);

    pthread_rwlock_unlock(&rwlock);
    printf("Writer %d: unlock the write lock\n", id);

    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
	int reader_ids[NUM_READERS];
	int rc;

    for (int i = 0; i < NUM_READERS; i++)
    {
		reader_ids[i] = i;
		rc = pthread_create(&readers[i], NULL, reader_job, &reader_ids[i]);
		if (rc)
		{
			fprintf(stderr, "Error creating thread: %d\n", rc);
			exit(EXIT_FAILURE);
		}
    }

	int i; // avoid stack aliasing
	for (i = 0; i < NUM_WRITERS; i++)
	{
		rc = pthread_create(&writers[i], NULL, writer_job, &i);
		if (rc)
		{
			fprintf(stderr, "Error creating thread: %d\n", rc);
			exit(EXIT_FAILURE);
		}
	}

    for (int i = 0; i < NUM_READERS; i++)
    {
		rc = pthread_join(readers[i], NULL);
		if (rc)
		{
			fprintf(stderr, "Error join thread: %d\n", rc);
			exit(EXIT_FAILURE);
		}
    }

    for (int i = 0; i < NUM_WRITERS; i++)
    {
		rc = pthread_join(writers[i], NULL);
		if (rc)
		{
			fprintf(stderr, "Error join thread: %d\n", rc);
			exit(EXIT_FAILURE);
		}
    }

    pthread_rwlock_destroy(&rwlock);

    printf("Main completed\n");
    return 0;
}