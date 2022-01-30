#include "push_swap.h"

void    pa(t_list **stack_a, t_list **stack_b)
{
    t_list  *first_b;

    if (!(*stack_a && (*stack_a)->next) ||
        !(*stack_b && (*stack_b)->next))
        return ;
    first_b = *stack_b;
    *stack_b = (*stack_b)->next;
    ft_lstadd_front(stack_a, first_b);
}

void    pb(t_list **stack_a, t_list **stack_b)
{
    pa(stack_b, stack_a);
}
