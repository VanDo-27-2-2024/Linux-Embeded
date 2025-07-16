#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3

int counter = 0;
pthread_mutex_t lock;

void* increase(void* arg)
{
    pthread_mutex_lock(&lock);

    for(int i = 0; i < 1000000; i++)
    {
        counter++;
    }

    pthread_mutex_unlock(&lock);

    return NULL;
}

int main()
{
    pthread_t thread_list[NUM_THREADS];
    int rc;

	for (int i = 0; i < NUM_THREADS; i++)
	{
		rc = pthread_create(&thread_list[i], NULL, increase, NULL);
		if (rc)
		{
			fprintf(stderr, "Error creating thread: %d\n", rc);
			exit(EXIT_FAILURE);
		}
	}


    for (int i = 0; i < NUM_THREADS; i++)
	{
		rc = pthread_join(thread_list[i], NULL);
		if (rc)
		{
			fprintf(stderr, "Error join thread: %d\n", rc);
			exit(EXIT_FAILURE);
		}
	}

    pthread_mutex_destroy(&lock);

    printf("Counter: %d\n", counter);

    return 0;
}