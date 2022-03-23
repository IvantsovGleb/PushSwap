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


int     error(const char *message)
{
    if (!message)
        return (0);
    write(2, message, ft_strlen(message));
    return (0);
}

void    *null_error(const char *message)
{
    if (!message)
        return ((void *) 0);
    write(2, message, ft_strlen(message));
    return ((void *) 0);
}