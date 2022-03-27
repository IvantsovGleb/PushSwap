/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:51:30 by fsinestr          #+#    #+#             */
/*   Updated: 2022/03/27 15:28:31 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*generate_stack(int *ia, int n)
{
	t_list	*head;
	t_list	*new;
	t_list	*last;
	int		*i_el;
	int		i;

	head = (void *) 0;
	i = 0;
	while (i < n)
	{
		i_el = malloc(sizeof(*ia));
		if (!i_el)
			return (free_stack(&head));
		*i_el = ia[i];
		new = ft_lstnew((void *)i_el);
		if (!new)
			return (free_stack(&head));
		ft_lstadd_back(&head, new);
		i++;
	}
	last = ft_lstlast(head);
	last->next = (void *) 0;
	return (head);
}

static int	*get_sorted_copy(const int *ia, int n)
{
	int	*ia_copy;

	ia_copy = malloc(n * sizeof(*ia_copy));
	if (!ia_copy)
		return ((void *) 0);
	ft_memcpy(ia_copy, ia, n * sizeof(*ia));
	bubble_sort(ia_copy, n);
	return (ia_copy);
}

static int	*generate_index_array(const int *ia, const int *ia_cp, int n)
{
	int	*ind_a;
	int	j;
	int	i;

	ind_a = malloc(n * sizeof(*ind_a));
	if (!ind_a)
		return ((void *) 0);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (ia_cp[i] == ia[j])
			{
				ind_a[j] = i;
				break ;
			}
			j++;
		}
		i++;
	}
	return (ind_a);
}

t_list	*init_stack(int *ia, int n)
{
	t_list	*stack_a;
	int		*ind_a;
	int		*ia_cp;

	ia_cp = get_sorted_copy(ia, n);
	if (!ia_cp)
		return ((void *) 0);
	ind_a = generate_index_array(ia, ia_cp, n);
	if (!ind_a)
		return (free_array(&ia_cp));
	stack_a = generate_stack(ind_a, n);
	if (!stack_a)
	{
		free(ia_cp);
		return (free_array(&ind_a));
	}
	free(ia_cp);
	free(ind_a);
	return (stack_a);
}
