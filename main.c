#include "push_swap.h"



int     main(int argc, char *argv[])
{
    char    **args;
    int     n;

    if (argc < 2)
        exit(1);
    if (argc == 2)
    {
        n = 0;
        args = split(argv[1], &n);
        push_swap(n, args);
        memfree(args);
    }
    else
        push_swap(argc - 1, ++argv);
    return (0);
}

