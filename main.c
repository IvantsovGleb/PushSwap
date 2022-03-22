#include "push_swap.h"

int     main(int argc, char *argv[])
{
    t_arg   arg;

    if (!extract_params(argc, argv, &arg))
        return (0);
    init_array(&arg);
    return (0);
}
