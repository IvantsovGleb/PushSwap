#include "../push_swap.h"

void    sa(t_list **stack_a)
{
    t_list  *first;

    if (!(*stack_a && (*stack_a)->next))
        return ;
    first = *stack_a;
    *stack_a = (*stack_a)->next;
    ft_lstadd_front(&(*stack_a)->next, first);
    write(1, "sa\n", 3);
}

void    sb(t_list **stack_b)
{
    t_list  *first;

    if (!(*stack_b && (*stack_b)->next))
        return ;
    first = *stack_b;
    *stack_b = (*stack_b)->next;
    ft_lstadd_front(&(*stack_b)->next, first);
    write(1, "sb\n", 3);
}

void    ss(t_list **stack_a, t_list **stack_b)
{
    sa(stack_a);
    sb(stack_b);
}