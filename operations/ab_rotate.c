/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:52:51 by fsinestr          #+#    #+#             */
/*   Updated: 2022/03/27 15:34:29 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*first;
	t_list	*last;

	if (!(*stack_a && (*stack_a)->next))
		return ;
	first = *stack_a;
	*stack_a = (*stack_a)->next;
	first->next = (void *) 0;
	last = ft_lstlast(*stack_a);
	last->next = first;
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	t_list	*first;
	t_list	*last;

	if (!(*stack_b && (*stack_b)->next))
		return ;
	first = *stack_b;
	*stack_b = (*stack_b)->next;
	first->next = (void *) 0;
	last = ft_lstlast(*stack_b);
	last->next = first;
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
