#include <stdio.h>
#include "strutils.h"

int main()
{
    char str1[] = "Hello World";
    char str2[] = "  NoSpace ";
    char str3[] = "123";
    int value;

    printf("Before reverse: %s\n", str1);
    str_reverse(str1);
    printf("After reverse: %s\n\n", str1);

    printf("Before trim: %s\n", str2);
    str_trim(str2);
    printf("After trim: %s\n\n", str2);

    printf("Before convert to int: %s\n", str3);
    if (str_to_int(str3, &value))
    {
        printf("After convert to int: %d\n", value);
    }

    return 0;
}