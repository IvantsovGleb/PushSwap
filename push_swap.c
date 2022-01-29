#include "push_swap.h"

int     main(int argc, char *argv[])
{
    t_list  *stack_a;
//    t_list  *stack_b;

    printf("argc %d\n", argc);
    if (argc < 2)
        exit(1);
    stack_a = init(argc, argv);
//    if (stack_a)
//        stack_b = create_list();
    print_list(stack_a);

    sa(&stack_a);
    print_list(stack_a);

    ft_lstclear(&stack_a, free);
//    ft_lstclear(&stack_b, free);
    return (0);
}

