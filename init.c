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
    t_list  *travers;

    tmp = lst;
    while (tmp)
    {
        travers = tmp->next;
        while (travers)
        {
            if (*(int *)(tmp->content) == *(int *)(travers->content))
                return (1);
            else
                travers = travers->next;
        }
        tmp = tmp->next;
    }
    return (0);
}

static t_list   *init_stack(int n, char *args[])
{
    t_list  *stack;
    t_list  *tmp;
    int     *arg;

    stack = create_list(n);
    if (!stack || !args)
        return ((void *) 0);
    tmp = stack;
    while (*args && tmp)
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
            handle_error(&stack);
            break ;
        }
    }
    return (stack);
}

t_list  *init(int argc, char *argv[])
{
    char    **args;
    t_list  *stack_a;
    int     n;

    stack_a = (void *) 0;
    if (argc == 2)
    {
        args = ft_split(argv[1], ' ');
        if (args)
        {
            n = count_args(argv[1]);
            stack_a = init_stack(n, args);
            memfree(args);
        }
    }
    else
        stack_a = init_stack(argc - 1, ++argv);
    if (stack_a && duplicates(stack_a))
        handle_error(&stack_a);
    return (stack_a);
}
