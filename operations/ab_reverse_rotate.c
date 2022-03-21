#include "../push_swap.h"

void    rra(t_list **stack_a)
{
    t_list  *last;
    t_list  *traverse;

    if (!(*stack_a && (*stack_a)->next))
        return ;
    last = ft_lstlast(*stack_a);
    ft_lstadd_front(stack_a, last);
    traverse = (*stack_a);
    while (traverse)
    {
        if (traverse->next == last)
            break ;
        traverse = traverse->next;
    }
    traverse->next = (void *) 0;
    write(1, "rra\n", 4);
}


void    rrb(t_list **stack_b)
{

    t_list  *last;
    t_list  *traverse;

    if (!(*stack_b && (*stack_b)->next))
        return ;
    last = ft_lstlast(*stack_b);
    ft_lstadd_front(stack_b, last);
    traverse = (*stack_b);
    while (traverse)
    {
        if (traverse->next == last)
            break ;
        traverse = traverse->next;
    }
    traverse->next = (void *) 0;
    write(1, "rrb\n", 4);
}

void    rrr(t_list **stack_a, t_list **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}
