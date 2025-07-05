#ifndef STRUTILS_H
#define STRUTILS_H

// Reverses a string in-place.
void str_reverse(char *str);

// Removes leading and trailing whitespace from a string.
void str_trim(char *str);

// Safely converts a string to an integer.
int str_to_int(const char *str, int *out_num);

#endif