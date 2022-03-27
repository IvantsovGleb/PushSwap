/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:51:55 by fsinestr          #+#    #+#             */
/*   Updated: 2022/03/27 15:11:26 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
	int	first;
	int	middle;
	int	last;

	first = *(int *)((*stack_a)->content);
	middle = *(int *)((*stack_a)->next->content);
	last = *(int *)(ft_lstlast(*stack_a)->content);
	if (first > middle && first < last && middle < last)
		sa(stack_a);
	else if (first > middle && first > last && middle < last)
		ra(stack_a);
	else if (first < middle && first < last && middle > last)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (first < middle && first > last && last < middle)
		rra(stack_a);
	else if (first > middle && first > last && middle > last)
	{
		ra(stack_a);
		sa(stack_a);
	}
}
