#include "push_swap.h"

t_list  *sort_stack(t_list **stack_a)
{
    t_list  *stack_b;

    stack_b = (void *) 0;
    if (*stack_a && ((*stack_a)->next == (void *) 0))
        return (*stack_a);

    if (*(int *)((*stack_a)->content) > *(int *)((*stack_a)->next->content))
        sa(stack_a);
    while (*stack_a)
    {
        if (!stack_b)
            pb(stack_a, &stack_b);
        if (*(int *)((*stack_a)->content) > *(int *)(stack_b->content))
        {
            if (!(*stack_a && (*stack_a)->next))
            {
                pb(stack_a, &stack_b);
                *stack_a = (void *) 0;
            }
            else
                pb(stack_a, &stack_b);
        }
        else
        {
            ra(stack_a);
            pa(stack_a, &stack_b);
            rra(stack_a);
        }
    }
//    printf("\n");
//    print_list(stack_b);
//    printf("-\nb\n\n");
    while (stack_b)
        pa(stack_a, &stack_b);
    stack_b = (void *) 0;
    return (*stack_a);
}