#include "push_swap.h"

void    ra(t_list **stack_a)
{
    t_list  *first;
    t_list  *last;

    if (!(*stack_a && (*stack_a)->next))
        return ;
    first = *stack_a;
    *stack_a = (*stack_a)->next;
    first->next = (void *) 0;
    last = ft_lstlast(*stack_a);
    last->next = first;
}

void    rb(t_list **stack_b)
{
    ra(stack_b);
}

void    rr(t_list **stack_a, t_list **stack_b)
{
    ra(stack_a);
    ra(stack_b);
}
