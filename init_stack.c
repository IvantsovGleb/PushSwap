#include "push_swap.h"

static t_list   *generate_stack(int *array, int n)
{
    t_list  *head;
    t_list  *new;
    t_list  *last;
    int     *i_el;
    int i;

    head = (void *) 0;
    i = 0;
    while (i < n)
    {
        i_el = malloc(sizeof(*array));
        if (!i_el)
            return (free_stack(&head));
        *i_el = array[i];
        new = ft_lstnew((void *)i_el);
        if (!new)
            return (free_stack(&head));
        ft_lstadd_back(&head, new);
        i++;
    }
    last = ft_lstlast(head);
    last->next = (void *) 0;
    return (head);
}

t_list  *init_stack(int *array, int n)
{
    t_list  *stack_a;

    stack_a = generate_stack(array, n);
    if (!stack_a)
        return ((void *) 0);
    return (stack_a);
}