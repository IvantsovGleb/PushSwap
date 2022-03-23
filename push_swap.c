#include "push_swap.h"

//static t_bool   issorted(t_list *stack)
//{
//    t_list  *tmp;
//
//    tmp = stack;
//    while (tmp)
//    {
//        if (tmp->next && (*(int *)tmp->content > *(int *)tmp->next->content))
//            return (FALSE);
//        tmp = tmp->next;
//    }
//    return (TRUE);
//}

static int      count_bits(int num)
{
    int     count;
    int     i;

    count = 0;
    i = 0;
    while (i < (int)(sizeof(int) * 8))
    {
        if (num & (1 << i))
        {
            if (count < i + 1)
                count = i + 1;
        }
        i++;
    }
    return (count);
}

static void sort_stack(t_list **stack_a, t_list **stack_b)
{
    int     size;
    int     max_bits;
    int     i;
    int     j;

    size = ft_lstsize(*stack_a);
    max_bits = count_bits(size - 1);
    printf("max_bits=%d\n", max_bits);
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j++ < size)
        {
            if (*(int *)(*stack_a)->content & (1 << i))
                ra(stack_a);
            else
                pb(stack_a, stack_b);
        }
        while (*stack_b)
            pa(stack_a, stack_b);
        i++;
    }
}

void    push_swap(t_list **stack_a)
{
    t_list  *stack_b;

    stack_b = (void *) 0;
    sort_stack(stack_a, &stack_b);
}