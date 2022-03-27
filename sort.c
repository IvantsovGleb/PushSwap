/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:51:58 by fsinestr          #+#    #+#             */
/*   Updated: 2022/03/27 15:18:14 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_bits(int num)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < (int)(sizeof(int) * 8))
	{
		if (num & (1 << i))
		{
			if (count < i + 1)
				count = i + 1;
		}
		i++;
	}
	return (count);
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = ft_lstsize(*stack_a);
	max_bits = count_bits(size - 1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size && !issorted(*stack_a))
		{
			if (*(int *)(*stack_a)->content & (1 << i))
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
