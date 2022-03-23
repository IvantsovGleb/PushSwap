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
        return (0);
    t_list  *p_lst = stack;
    while (p_lst)
    {
        printf("%d\n", *(int *)p_lst->content);
        p_lst = p_lst->next;
    }
    return (0);
}
