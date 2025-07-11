#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    pid_t pid = fork();
    int status;

    if (pid == -1)
    {
        printf("Can not create child process\n");
        exit(-1);
    }
    else if (pid == 0)
    {
        printf("This is child process (PID: %d)\n", getpid());
        exit(10);
    }
    else
    {
        pid_t p;

        printf("This is dad process (PID: %d), create child process (PID: %d)\n", getpid(), pid);
        printf("Dad process waiting ...\n");

        p = wait(&status);
        if (WIFEXITED(status))
        {
            printf("Child process (PID: %d) finishes with exit code: %d\n", p, WEXITSTATUS(status));
        }
        else
        {
            printf("Child process does not finish normally !!!\n");
            perror("wait failed");
        }
    }

    return 0;
}