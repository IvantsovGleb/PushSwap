/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:51:35 by fsinestr          #+#    #+#             */
/*   Updated: 2022/03/30 22:25:06 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_params(char **params)
{
	int	n;

	n = 0;
	while (params[n])
		n++;
	return (n);
}

t_bool	extract_params(int argc, char *argv[], t_arg *arg)
{
	if (argc < 2)
		return (FALSE);
	if (argc == 2)
	{
		arg->params = ft_split(argv[1], ' ');
		arg->n = count_params(arg->params);
	}
	else
	{
		arg->params = &argv[1];
		arg->n = argc - 1;
	}
	return (TRUE);
}
