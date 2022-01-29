# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>

// temporary
void     print_list(t_list *lst);
//***************

t_list      *create_list(int n);
void        memfree(char **args);
void        handle_error(t_list **stack);
int         count_args(const char *s);

t_list      *init(int argc, char *argv[]);

void        sa(t_list **stack_a);
void        sb(t_list **stack_b);
void        ss(t_list **stack_a, t_list **stack_b);

#endif
