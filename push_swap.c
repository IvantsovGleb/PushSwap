#include "push_swap.h"

void    push_swap(int n, char **args)
{
    t_list  *stack_a;
    t_list  *stack_b;

    stack_a = create_stack(n);
    if (stack_a)
    {
        init(&stack_a, args);
        stack_b = (void *) 0;
        sort(&stack_a, &stack_b);

//        print_list(stack_a);
//        printf("-\na\n\n");
    }
    ft_lstclear(&stack_a, free);
}

