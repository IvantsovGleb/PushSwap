#include "push_swap.h"

void    *free_array(int **array)
{
    free(*array);
    return ((void *) 0);
}

void    *free_stack(t_list **lst)
{
    ft_lstclear(lst, free);
    return ((void *) 0);
}

void    mem_free(char **data)
{
    int i;

    i = 0;
    while (data[i])
        free(data[i++]);
    free(data);
}

void    *error(const char *message)
{
    if (message)
        write(2, message, ft_strlen(message));
    return ((void *) 0);
}

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
