#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

/* delete   */
# include <stdio.h>
/*          */

typedef enum e_bool
{
    FALSE,
    TRUE
}   t_bool;

typedef struct s_number
{
    unsigned long   nbr;
    int             sign;
}                   t_number;

typedef struct s_arg
{
    char    **params;
    int     n;
}           t_arg;

t_bool  extract_params(int argc, char *argv[], t_arg *arg);
int     parse_int(const char *s, int *i);

void    bubble_sort(int *array, int n);
int     *init_array(t_arg *arg);
t_list  *init_stack(int *array, int n);

t_bool  issorted(t_list *stack);
void    sort_three(t_list **stack_a);
void    sort_five(t_list **stack_a, t_list **stack_b);
void    sort_stack(t_list **stack_a, t_list **stack_b);

void    sa(t_list **stack_a);
void    sb(t_list **stack_b);
void    ss(t_list **stack_a, t_list **stack_b);

void    pa(t_list **stack_a, t_list **stack_b);
void    pb(t_list **stack_a, t_list **stack_b);

void    ra(t_list **stack_a);
void    rb(t_list **stack_b);
void    rr(t_list **stack_a, t_list **stack_b);

void    rra(t_list **stack_a);
void    rrb(t_list **stack_b);
void    rrr(t_list **stack_a, t_list **stack_b);

void    *error(const char *message);
void    *free_array(int **array);
void    *free_stack(t_list **lst);
void    mem_free(char **data);

#endif
