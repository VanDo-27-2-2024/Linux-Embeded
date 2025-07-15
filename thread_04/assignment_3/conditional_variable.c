#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

pthread_cond_t cond  = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int data = 0, data_ready = 0;

void* producer()
{
    for (int i = 0; i < 10; i++)
    {
        printf("Producer: Working...\n");
        data = rand();
        sleep(1);
    }

    // acquire a lock
    pthread_mutex_lock(&lock);

    data_ready = 1;
    printf("Producer: Data is ready!\n");
    pthread_cond_signal(&cond); // Signal consumer

    // release lock
    pthread_mutex_unlock(&lock);

    return NULL;
}

void* consumer()
{
    // acquire a lock
    pthread_mutex_lock(&lock);

    while (!data_ready)
    {
        printf("Consumer: Waiting for data...\n");
        pthread_cond_wait(&cond, &lock); // Wait for signal
    }

    printf("Consumer: Processing data - print data: %d\n", data);

    data_ready = 0;

    // release lock
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    srand(time(NULL));

    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t2, NULL, consumer, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
