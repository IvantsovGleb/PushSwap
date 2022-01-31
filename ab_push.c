#include "push_swap.h"

void    pa(t_list **stack_a, t_list **stack_b)
{
    t_list  *first_b;

    if (!*stack_b)
        return ;
    first_b = *stack_b;
    *stack_b = (*stack_b)->next;
    ft_lstadd_front(stack_a, first_b);
    write(1, "pa\n", 3);
}

void    pb(t_list **stack_a, t_list **stack_b)
{
    t_list  *first_a;

    if (!*stack_a)
        return ;
    first_a = *stack_a;
    *stack_a = (*stack_a)->next;
    ft_lstadd_front(stack_b, first_a);
    write(1, "pb\n", 3);
}
