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

void    memfree(char **args)
{
    int     i;

    i = 0;
    while (args[i])
        free(args[i++]);
    free(args);
}

char    **split(const char *s, int *n)
{
    size_t	i;
    char    **args;

    args = ft_split(s, ' ');
    if (!args)
        return ((void *) 0);
    i = 0;
    while (s[i])
    {
        if ((s[i + 1] && s[i] != ' ' && s[i + 1] == ' ')
            || (s[i] != ' ' && !s[i + 1]))
            (*n)++;
        i++;
    }
    return (args);
}

void    handle_error(t_list **stack)
{
    ft_lstclear(stack, free);
    write(2, "Error\n", 6);
    *stack = (void *) 0;
}

void     print_list(t_list *a)
{
    t_list  *tmp;

    tmp = a;
    while (tmp)
    {
        printf("%d\n", *((int *)(tmp->content)));
//        printf("%p\n", (char *)tmp);
        tmp = tmp->next;
    }
//    printf("%p\n", (char *)tmp);
}