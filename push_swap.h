# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>

// temporary
void     print_list(t_list *lst);
//***************

// utils
t_list      *create_stack(int n);
void        memfree(char **args);
void        handle_error(t_list **stack);
char        **split(const char *s, int *n);
//**************

t_list      *init(t_list **stack, char *args[]);

void        sa(t_list **stack_a);
void        sb(t_list **stack_b);
void        ss(t_list **stack_a, t_list **stack_b);

void        pa(t_list **stack_a, t_list **stack_b);
void        pb(t_list **stack_a, t_list **stack_b);

void        ra(t_list **stack_a);
void        rb(t_list **stack_b);
void        rr(t_list **stack_a, t_list **stack_b);

void        rra(t_list **stack_a);
void        rrb(t_list **stack_b);
void        rrr(t_list **stack_a, t_list **stack_b);
#endif
