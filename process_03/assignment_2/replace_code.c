#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    pid_t pid = 0;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <command>\nSupported commands: ls, date, pwd\n", argv[0]);
        return 1;
    }

    setenv("MY_COMMAND", argv[1], 1);

    pid = fork();
    if (pid == -1)
    {
        perror("fork failed");
        return 1;
    }
    else if (pid == 0)
    {
        char* command = getenv("MY_COMMAND");

        if (strcmp(command, "ls") == 0)
        {
            execlp("ls", "ls", NULL);
        }
        else if (strcmp(command, "date") == 0)
        {
            execlp("date", "date", NULL);
        }
        else if (strcmp(command, "pwd") == 0)
        {
            execlp("pwd", "pwd", NULL);
        }
        else
        {
            fprintf(stderr, "Unsupported command: %s\nSupported commands: ls, date, pwd\n", command);
            return 1;
        }
    }
    else
    {
        wait(NULL);
    }

    return 0;
}
