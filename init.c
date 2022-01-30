#include "push_swap.h"

static int     parse_long(const char *str, int *si)
{
    int     flag;
    int     errn;
    long    sl;
    char    *endptr;

    if (ft_isspace(str[0]))
        return (0);
    flag = 1;
    errn = 0;
    sl = ft_strtol(str, &endptr, 10, &errn);
    if (str == endptr || *endptr != '\0' ||
        ((sl == LONG_MIN || sl == LONG_MAX) && errn == ERANGE) ||
        (sl < INT_MIN || sl > INT_MAX))
        flag = 0;
    else
        *si = (int) sl;
    return (flag);
}

static int      duplicates(t_list *lst)
{
    t_list  *tmp;
    t_list  *traverse;

    tmp = lst;
    while (tmp)
    {
        traverse = tmp->next;
        while (traverse)
        {
            if (*(int *)(tmp->content) == *(int *)(traverse->content))
                return (1);
            else
                traverse = traverse->next;
        }
        tmp = tmp->next;
    }
    return (0);
}

t_list      *init(t_list **stack, char *args[])
{
    t_list  *tmp;
    int     *arg;

    tmp = *stack;
    while (*stack && *args && tmp)
    {
        arg = malloc(sizeof(int));
        if (arg && parse_long(*args++, arg))
        {
            tmp->content = (void *)arg;
            tmp = tmp->next;
        }
        else
        {
            free(arg);
            handle_error(stack);
        }
    }
    if (duplicates(*stack))
        handle_error(stack);
    return (*stack);
}
