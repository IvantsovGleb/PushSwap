/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:51:33 by fsinestr          #+#    #+#             */
/*   Updated: 2022/03/30 22:24:21 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = (void *) 0;
	if (issorted(*stack_a))
		return ;
	else if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else if (ft_lstsize(*stack_a) == 5)
		sort_five(stack_a, &stack_b);
	else
		sort_stack(stack_a, &stack_b);
}

int	main(int argc, char *argv[])
{
	t_arg	arg;
	int		*array;
	t_list	*stack;

	stack = (void *) 0;
	if (!extract_params(argc, argv, &arg))
		return (0);
	array = init_array(&arg);
	if (argc == 2)
		mem_free(arg.params);
	if (!array)
		return (0);
	stack = init_stack(array, arg.n);
	if (!stack)
	{
		free(array);
		return (0);
	}
	push_swap(&stack);
	free(array);
	ft_lstclear(&stack, free);
	return (0);
}
