#include <iostream>
#include <algorithm>

#include "log.h"

#define COMPILE_SINGLE_FILE 0

template <typename Iter>
bool next_perm(Iter first, Iter last);

#if COMPILE_SINGLE_FILE
int main()
{
    std::string num = "2142";
    do {
        LOG(num);
    }while (next_perm(num.begin(), num.end()));
}
#endif

template<typename Iter>
bool next_perm(Iter first, Iter last)
{
    if (first == last)
        return false;
    Iter i = first;
    ++i;
    if (i == last)
        return false;
    i = last;
    --i;

    for(;;)
    {
        Iter ii = i;
        --i;
        if (*i < *ii)
        {
            Iter j = last;
            while (!(*i < *--j))
            {}
            std::iter_swap(i, j);
            std::reverse(ii, last);
            return true;
        }
        if (i == first)
        {
            std::reverse(first, last);
            return false;
        }
    }
}

// source : http://wordaligned.org/articles/next-permutation
