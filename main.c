#include "push_swap.h"

 t_bool   issorted(t_list *stack)
{
    t_list  *tmp;

    tmp = stack;
    while (tmp)
    {
        if (tmp->next && (*(int *)tmp->content > *(int *)tmp->next->content))
            return (FALSE);
        tmp = tmp->next;
    }
    return (TRUE);
}

static void    push_swap(t_list **stack_a)
{
    t_list  *stack_b;

    t_list  *p_stack = *stack_a;
    while(p_stack)
    {
        printf("%d ", *(int *)p_stack->content);
        p_stack = p_stack->next;
    }
    printf("\n");

    stack_b = (void *) 0;
    if (issorted(*stack_a))
        return ;
    else if (ft_lstsize(*stack_a) == 3)
        sort_three(stack_a);
    else if (ft_lstsize(*stack_a) == 5)
        sort_five(stack_a, &stack_b);
    else
        sort_stack(stack_a, &stack_b);

    p_stack = *stack_a;
    while(p_stack)
    {
        printf("%d ", *(int *)p_stack->content);
        p_stack = p_stack->next;
    }
    printf("\n");

    if (issorted(*stack_a))
        printf("\nok\n");
}

int     main(int argc, char *argv[])
{
    t_arg   arg;
    int     *array;
    t_list  *stack;
    
    if (!extract_params(argc, argv, &arg))
        return (0);
    array = init_array(&arg);
    if (!array)
        return (0);
    stack = init_stack(array, arg.n);
    if (!stack)
    {
        free_array(&array);
        return (0);
    }
    push_swap(&stack);
    free_array(&array);
    free_stack(&stack);
    return (0);
}
