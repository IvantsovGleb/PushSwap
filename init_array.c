#include "push_swap.h"

static int  duplicates(const int *array, int n)
{
    int i;
    int j;
    int el;

    i = 0;
    while (i < n - 1)
    {
        el = array[i];
        j = i + 1;
        while (j < n)
        {
            if (el == array[j])
                return (FALSE);
            j++;
        }
        i++;
    }
    return (TRUE);
}

static int  *get_helper_array(char *params[], int n)
{
    int *array;
    int i;

    array = malloc( (n - 1) * sizeof(*array));
    if (!array)
        return ((void *) 0);
    i = 0;
    while (params[i])
    {
        if (!parse_int(params[i], &array[i]))
            return (array);
        i++;
    }
    return (array);
}

static void    swap(int *from, int *to)
{
    int tmp;

    tmp = *to;
    *to = *from;
    *from = tmp;
}

static void    bubble_sort(int *array, int n)
{
    int i;
    int j;

    i = 0;
    while (i < n - 1)
    {
        j = i + 1;
        while (j < n)
        {
            if (array[i] > array[j])
                swap(&array[i], &array[j]);
            j++;
        }
        i++;
    }
}

int *init_array(t_arg *arg)
{
    int *array;

    array = get_helper_array(arg->params, arg->n);
    if (!array)
    {
        free(array);
        return ((void *) 0);
    }
    if (!duplicates(array, arg->n))
    {
        free(array);
        return ((void *) 0);
    }
    bubble_sort(array, arg->n);
    return (array);
}
