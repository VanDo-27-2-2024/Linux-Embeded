#include "strutils.h"
#include "stdio.h"

void str_reverse(char *str)
{
    if (str == NULL)
    {
        printf("String is NULL\n");
        return;
    }

    int count = 0;
    while (str[count] != '\0')
    {
        count++;
    }

    if (count == 0)
    {
        return;
    }

    for (int i = 0; i < count/2; i++)
    {
        char tmp = str[i];
        str[i] = str[count - i -1];
        str[count - i - 1] = tmp;
    }
}

void str_trim(char *str)
{
    if (str == NULL) return;

    // Step 1: Find start (first non-whitespace)
    int start = 0;
    while (str[start] == ' ' || str[start] == '\t' || str[start] == '\n')
    {
        start++;
    }

    // Step 2: Find end (last non-whitespace)
    int end = start;
    while (str[end] != '\0')
    {
        end++;
    }
    end--;

    while (end >= start && (str[end] == ' ' || str[end] == '\t' || str[end] == '\n'))
    {
        end--;
    }

    // Step 3: Shift trimmed content to beginning
    int i = 0;
    while (start <= end)
    {
        str[i++] = str[start++];
    }

    str[i] = '\0'; // null-terminate
}

// Safely converts a string to an integer.
// Returns 1 on success, 0 on failure (invalid format).
int str_to_int(const char *str, int *out_num)
{
    int sign = 1;
    int result = 0;
    int i = 0;

    if (str == NULL || out_num == NULL) return 0;

    // Skip leading whitespace
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
        i++;
    }

    // Handle optional '+' or '-' sign
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    // At least one digit required
    if (str[i] < '0' || str[i] > '9') {
        return 0;
    }

    // Convert digits to integer
    while (str[i] >= '0' && str[i] <= '9') {
        int digit = str[i] - '0';

        // Optional: Detect overflow (not implemented here for simplicity)
        result = result * 10 + digit;
        i++;
    }

    // If trailing non-digit characters exist return fail
    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            return 0;
        }
        i++;
    }

    *out_num = result * sign;

    return 1;
}
