#include <iostream>
#include "log.h"

#define COMPILE_SINGLE_FILE 0

#if COMPILE_SINGLE_FILE
#include <string.h>
#endif

// function signatures
template <typename T>
void permute(T* array, int first, int last);

template <typename T>
void swap(T& x, T& y);

#if COMPILE_SINGLE_FILE
int main()
{
    char arr[] = "ABC";
    int first = 0;
    int last = strlen(arr) - 1;
    permute<char>(arr, first, last);

    return 0;
}
#endif

template <typename T>
void swap(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}

template <typename T>
void permute(T* array, int first, int last)
{
    if (first == last) {
        LOG(array);
    } else {
        for (int i = first; i <= last; ++i) {
            swap(array[first], array[i]);
            permute(array, first+1, last);
            swap(array[i], array[first]);
        }
    }
}
