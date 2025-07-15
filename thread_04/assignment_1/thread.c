#include <stdio.h>
#include <pthread.h>

void* job(void* arg)
{
    printf("Thread với ID <%ld> đang chạy!\n", pthread_self());
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    if (pthread_create(&t1, NULL, job, NULL) != 0)
    {
        perror("Failed to create thread 1");
        return 1;
    }

    if (pthread_create(&t2, NULL, job, NULL) != 0)
    {
        perror("Failed to create thread 1");
        return 1;
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}