#include "push_swap.h"

void    sa(t_list **stack_a)
{
    t_list  *first;

    if (!(*stack_a && (*stack_a)->next))
        return ;
    first = *stack_a;
    *stack_a = (*stack_a)->next;
    ft_lstadd_front(&(*stack_a)->next, first);
}

void    sb(t_list **stack_b)
{
    sa(stack_b);
}

void    ss(t_list **stack_a, t_list **stack_b)
{
    sa(stack_a);
    sa(stack_b);
}