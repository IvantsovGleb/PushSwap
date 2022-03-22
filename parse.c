#include "push_swap.h"

static int  uo_flow(unsigned long *nbr, int sign, int c)
{
    unsigned long   cutoff;
    int             cutlim;

    cutoff = (unsigned long)LONG_MAX / 10;
    if (sign)
        cutlim = (unsigned long)LONG_MIN % 10;
    else
        cutlim = (unsigned long)LONG_MAX % 10;
    if (*nbr > cutoff || (*nbr == cutoff && c > cutlim))
    {
        if (sign)
            *nbr = LONG_MIN;
        else
            *nbr = LONG_MAX;
        return (1);
    }
    return (0);
}

static void     to_int(const char **p_s, const char **end_p, t_number *num, int *errn)
{
    int c;

    num->nbr = 0;
    while (**p_s && ft_isdigit((unsigned char)**p_s))
    {
        c = **p_s - '0';
        *errn = uo_flow(&num->nbr,num->sign, c);
        if (!*errn)
            num->nbr = num->nbr * 10 + c;
        else
            break ;
        *end_p = ++*p_s;
    }
}

static long    my_atol(const char *nptr, char **endptr, int *err)
{
    t_number        num;
    const char      *p_s;
    const char      *end_p;

    p_s = nptr;
    end_p = nptr;
    num.sign = 0;
    if (*p_s == '-')
    {
        num.sign = 1;
        p_s++;
    }
    to_int(&p_s, &end_p, &num, err);
    if (!*err && num.sign)
        num.nbr = -num.nbr;
    if (endptr)
        *endptr = (char *)end_p;
    return ((long)num.nbr);
}

int     parse_int(const char *s, int *i)
{
    int     err;
    char    *end_p;
    long    l;

    err = 0;
    l = my_atol(s, &end_p, &err);
    if (s == end_p || *end_p != '\0'
            || ((l == LONG_MIN || l == LONG_MAX) && err)
            || (l < INT_MIN || l > INT_MAX))
        return (0);
    else
        *i = (int) l;
    return (1);
}

//    if (s == end_p)
//        printf("%s: not a decimal number\n", s);
//    else if (*end_p != '\0')
//        printf("%s: extra characters at end of input\n", s);
//    else if ((l == LONG_MIN || l == LONG_MAX) && err)
//        printf("%s: out of range of type long\n", s);
//    else if (l < INT_MIN || l > INT_MAX)
//        printf("less than INT_MIN or greater than INT_MAX\n");