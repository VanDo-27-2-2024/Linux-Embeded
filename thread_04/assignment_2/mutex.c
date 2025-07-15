#include <stdio.h>
#include <pthread.h>


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
    pthread_t t1, t2, t3;

    if (pthread_create(&t1, NULL, increase, NULL) != 0)
    {
        perror("Failed to create thread 1");
        return 1;
    }

    if (pthread_create(&t2, NULL, increase, NULL) != 0)
    {
        perror("Failed to create thread 1");
        return 1;
    }

    if (pthread_create(&t3, NULL, increase, NULL) != 0)
    {
        perror("Failed to create thread 1");
        return 1;
    }


    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_mutex_destroy(&lock);

    printf("Counter: %d\n", counter);

    return 0;
}