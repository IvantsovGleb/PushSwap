#include "push_swap.h"

static int     issorted(t_list *stack)
{
    t_list  *tmp;

    tmp = stack;
    while (tmp)
    {
        if (tmp->next && (*(int *)tmp->content > *(int *)tmp->next->content))
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

static int      count_bits(t_list *stack)
{
    t_list  *tmp;
    int     count;
    int     n;
    int     i;

    count = 0;
    tmp = stack;
    while (tmp)
    {
        n = *(int *)tmp->content;
        i = 0;
        while (i < (int)(sizeof(int) * 8))
        {
            if (n & (1 << i))
            {
                if (count < i + 1)
                    count = i + 1;
            }
            i++;
        }
        tmp = tmp->next;
    }
    return (count);
}

static void     reverse_negatives(t_list **stack_a)
{
    t_list  *tmp;
    int     count;

    count = 0;
    tmp = *stack_a;
    while (tmp)
    {
        if (*(int *)tmp->content < 0)
            count++;
        tmp = tmp->next;
    }
    if (count < ft_lstsize(*stack_a))
    {
        while (count-- > 0)
            rra(stack_a);
    }
}

t_list      *sort(t_list **stack_a, t_list **stack_b)
{
    int     max_bits;
    int     size;
    int     i;
    int     j;

    if (issorted(*stack_a))
        return (*stack_a);
    max_bits = count_bits(*stack_a);
    size = ft_lstsize(*stack_a);
    i = 0;
    while (!issorted(*stack_a) && i < max_bits)
    {
        j = 0;
        while (j++ < size)
        {
            if (*(int *)(*stack_a)->content & (1 << i))
                ra(stack_a);
            else
                pb(stack_a, stack_b);
        }

//        print_list(*stack_a);
//        printf("-\na\n\n");
//
//        print_list(*stack_b);
//        printf("-\nb\n\n");

        while (*stack_b)
            pa(stack_a, stack_b);
        i++;
    }
    reverse_negatives(stack_a);
    return (*stack_a);
}
