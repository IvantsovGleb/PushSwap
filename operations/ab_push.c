/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:52:44 by fsinestr          #+#    #+#             */
/*   Updated: 2022/03/27 15:30:28 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_b;

	if (!*stack_b)
		return ;
	first_b = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstadd_front(stack_a, first_b);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_a;

	if (!*stack_a)
		return ;
	first_a = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_front(stack_b, first_a);
	write(1, "pb\n", 3);
}
