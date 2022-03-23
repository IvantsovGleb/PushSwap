#include "push_swap.h"

int     main(int argc, char *argv[])
{
    t_arg   arg;
    int     *array;
    t_list  *stack;
    
    if (!extract_params(argc, argv, &arg))
        return (0);
    array = init_array(&arg);
    if (!array)
        return (0);
    stack = init_stack(array, arg.n);
    if (!stack)
    {
        free_array(&array);
        return (0);
    }
    push_swap(&stack);
    free_array(&array);
    free_stack(&stack);
    return (0);
}
