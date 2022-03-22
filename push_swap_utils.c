#include "push_swap.h"

t_list  *create_stack(int n)
{
    t_list  *head;
    t_list  *new;
    int     i;

    if (n <= 0)
        return ((void *) 0);
    new = ft_lstnew(0);
    if (!new)
        return ((void *) 0);
    head = new;
    i = 1;
    while (i++ < n)
    {
        new = ft_lstnew(0);
        if (!new)
        {
            ft_lstclear(&head, free);
            return ((void *) 0);
        }
        ft_lstadd_back(&head, new);
    }
    return (head);
}

int     error(const char *message)
{
    if (!message)
        return (0);
    write(2, message, ft_strlen(message));
    return (0);
}
