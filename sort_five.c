#include "push_swap.h"

static int  find_pos(t_list **stack_a, int stack_b_top)
{
    t_list  *p_stack_a;
    int     count;

    count = 0;
    p_stack_a = *stack_a;
    while (p_stack_a)
    {
        if (stack_b_top > *(int *)(p_stack_a->content))
        {
            p_stack_a = p_stack_a->next;
            count++;
        }
        else
            break ;
    }
    return (count);
}

static void insert_el(t_list **stack_a, t_list **stack_b)
{
    int count;

    count = find_pos(stack_a,  *(int *)((*stack_b)->content));
    if (count == 0)
        pa(stack_a, stack_b);
    else if (count == ft_lstsize(*stack_a))
    {
        pa(stack_a, stack_b);
        ra(stack_a);
    }
}

static int  search_index(t_list *stack, int el)
{
    t_list  *p_stack;
    int     count;

    count = 0;
    p_stack = stack;
    while(p_stack)
    {
        if (el == *(int *)(p_stack->content))
            return (count);
        else
            count++;
        p_stack = p_stack->next;
    }
    return (-1);
}

void sort_five(t_list **stack_a, t_list **stack_b)
{
    int min_index;
    int max_index;

    min_index = search_index(*stack_a, 0);
    while (min_index-- > 0)
    {
        if (*(int *)(*stack_a)->content == 4)
            pb(stack_a, stack_b);
        else
            ra(stack_a);
    }
    pb(stack_a, stack_b);
    max_index = search_index(*stack_a, 4);
    if (max_index != -1)
    {
        while (max_index-- > 0)
            ra(stack_a);
        pb(stack_a, stack_b);
    }
    sort_three(stack_a);
    insert_el(stack_a, stack_b);
    insert_el(stack_a, stack_b);
}
