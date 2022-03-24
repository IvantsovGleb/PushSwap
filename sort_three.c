#include "push_swap.h"

void    sort_three(t_list **stack_a)
{
    int     first;
    int     middle;
    int     last;

    first = *(int *)((*stack_a)->content);
    middle = *(int *)((*stack_a)->next->content);
    last = *(int *)(ft_lstlast(*stack_a)->content);
    if (first > middle && first < last && middle < last) // 1 0 2
        sa(stack_a);
    else if (first > middle && first > last && middle < last) // 2 0 1
        ra(stack_a);
    else if (first < middle && first < last && middle > last) // 0 2 1
    {
        rra(stack_a);
        sa(stack_a);
    }
    else if (first < middle && first > last && last < middle) // 1 2 0
        rra(stack_a);
    else if (first > middle && first > last && middle > last) // 2 1 0
    {
        ra(stack_a);
        sa(stack_a);
    }
}
