#include "stdio.h"
#include "time.h"
#include <sys/stat.h>

int main(int argc, char* argv[])
{
    struct stat fstat;

    // Check number of parameter
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 0;
    }

    if (lstat(argv[1], &fstat) == -1)
    {
        perror("lstat failed");
        return 0;
    }

    printf("File Path: %s\n", argv[1]);

    // Determine and print file type
    printf("File Type: ");
    if (S_ISREG(fstat.st_mode))
    {
        printf("Regular File\n");
    }
    else if (S_ISDIR(fstat.st_mode))
    {
        printf("Directory\n");
    }
    else if (S_ISLNK(fstat.st_mode))
    {
        printf("Symbolic Link\n");
    }
    else
    {
        printf("Other\n");
    }

    printf("Size: %ld bytes\n", fstat.st_size);

    printf("Last Modified: %s", ctime(&fstat.st_mtime));

    return 0;
}
