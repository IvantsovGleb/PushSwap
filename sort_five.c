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

//static void insert_elem(t_list **stack_a, t_list **stack_b)
//{
//    int count;
//    int count_cp;
//
//    if (*stack_b == (void *) 0)
//        return ;
//    printf("inserting elem=%d\n", *(int *)((*stack_b)->content));
//    count = find_pos(stack_a, *(int *)((*stack_b)->content));
//    if (count == 0)
//        pa(stack_a, stack_b);
//    else if (count < ft_lstsize(*stack_a))
//    {
//        count_cp = count;
//        printf("-----------\n");
//        while (count-- > 0)
//            ra(stack_a);
//        pa(stack_a, stack_b);
//        count = 0;
//        while (count < count_cp)
//        {
//            rra(stack_a);
//            count++;
//        }
//        printf("-----------\n");
//    }
//    else if (count == ft_lstsize(*stack_a))
//    {
//        pa(stack_a, stack_b);
//        ra(stack_a);
//    }
//}

static void insert_elem(t_list **stack_a, t_list **stack_b)
{
    int count;
    int count_cp;

    count = find_pos(stack_a, *(int *)((*stack_b)->content));
    if (count == 0)
    {
        pa(stack_a, stack_b);
    }
    else if (count < ft_lstsize(*stack_a))
    {
        count_cp = count;
        while (count-- > 0)
            ra(stack_a);
        pa(stack_a, stack_b);
        count = 0;
        while (count < count_cp)
        {
            if (*stack_b)
            {
                if (find_pos(stack_a, *(int *) ((*stack_b)->content)) == 0)
                {
                    pa(stack_a, stack_b);
                    rra(stack_a);
                }
            }
            else
                rra(stack_a);
            count++;
        }
    }
    else if (count == ft_lstsize(*stack_a))
    {
        pa(stack_a, stack_b);
        ra(stack_a);
    }
}

void sort_five(t_list **stack_a, t_list **stack_b)
{
    int first;
    int second;

    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    first = *(int *)((*stack_b)->content);
    second = *(int *)((*stack_b)->next->content);
    if (first < second)
        sb(stack_b);
    sort_three(stack_a);
    insert_elem(stack_a, stack_b);
}
