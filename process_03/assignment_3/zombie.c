#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    pid = fork();
    if (pid == -1)
    {
        perror("fork failed");
        return 1;
    }
    else if (pid == 0) // child proccess
    {
        printf("This is child process - PID(%d), created by dad process - PID(%d)\n", getpid(), getppid());
        return 0;
    }
    else if (pid > 0) // dad process
    {
        printf("This is dad process - PID(%d), creates child process - PID(%d)\n", getpid(), pid);
        sleep(5);
        wait(NULL);
    }

    return 0;
}