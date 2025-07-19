#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE_THREAD_POOL 5
#define MAX_SIZE_QUEUE 50

static pthread_t thread_pool[SIZE_THREAD_POOL];
static pthread_mutex_t lock;
pthread_cond_t cond  = PTHREAD_COND_INITIALIZER;

typedef void (*func_ptr)(void);

typedef struct
{
    func_ptr items[MAX_SIZE_QUEUE];
    int front;
    int rear;
} queue;

// static int (*operations[4])(int, int[]);

static queue task_queue;

int data_ready = 0;

/////////////////// queue implementation




void initQueue(queue* q)
{
    q->front = 0;
    q->rear = 0;
}

int isEmpty(queue* q)
{
    return q->front == q->rear;
}

int isFull(queue* q) {
    return (q->rear + 1) % MAX_SIZE_QUEUE == q->front;
}

void enqueue(queue* q, func_ptr function) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->items[q->rear] = function;
    q->rear = (q->rear + 1) % MAX_SIZE_QUEUE;
    data_ready = 1;
}

func_ptr dequeue(queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return NULL;  // Return NULL instead of -1 for pointers
    }
    func_ptr res = q->items[q->front];
    q->front = (q->front + 1) % MAX_SIZE_QUEUE;

    if (isEmpty(q))
    {
        data_ready = 0;
    }
    return res;
}

//////////////////////////////

void push_task(void (*new_task)(void))
{
    pthread_mutex_lock(&lock);

    enqueue(&task_queue, new_task);

    pthread_cond_signal(&cond); // Signal threadpool
    pthread_mutex_unlock(&lock);
    
}

void* cook_task()
{
    pthread_mutex_lock(&lock);

    while (!data_ready)
    {
        printf("Thread pool: Waiting for task...\n");
        pthread_cond_wait(&cond, &lock); // Wait for signal
    }

    func_ptr task = dequeue(&task_queue);

    pthread_mutex_unlock(&lock); // avoid task excution lock the mutex - preventing other thread from acquire new task -> reduce concurrency

    if (task != NULL)
    {
        task();
    }

    



    return NULL;
}

int create_thread_pool()
{
    // to do create thread pool based on nums of cores
    for (int i = 0; i < SIZE_THREAD_POOL; i++)
    {
        pthread_t* t = malloc(sizeof(pthread_t));
        thread_pool[i] = pthread_create(t, NULL, cook_task, NULL);
    }

    return 0;
}

int wait_join_thread()
{
    for (int i = 0; i < SIZE_THREAD_POOL; i++)
    {
        pthread_join(thread_pool[i], NULL);
    }
}


void hello() {
    printf("Hello, world!\n");
}

void goodbye() {
    printf("Goodbye!\n");
}

void count() {
    static int i = 0;
    printf("Count: %d\n", ++i);
}


int main()
{

    initQueue(&task_queue);
    create_thread_pool();

    sleep(2);

    push_task(hello);
    push_task(goodbye);
    push_task(count);
    push_task(count);

    // Enqueue some functions
    // enqueue(&task_queue, hello);
    // enqueue(&task_queue, goodbye);
    // enqueue(&task_queue, count);
    // enqueue(&task_queue, count);



    // sleep(5);

    wait_join_thread();



    return 0;
}