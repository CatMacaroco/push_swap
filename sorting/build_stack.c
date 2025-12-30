/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:55:17 by cmacaroc          #+#    #+#             */
/*   Updated: 2025/12/30 16:47:54 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*handle_single_arg(char *av)
{
	char	**split;
	t_list	*a;
	
	a = NULL;
	split = ft_split(av, ' ');
	parsing_split(split, &a);
	return (a);
}

t_list *handle_multi_args(int ac, char *av[])
{
	t_list	*a;
	long	num;
	int 	i;
	
	a = NULL;
	i = 1;
	while (i < ac)
	{
		num = ft_atol(av[i]);
		if (num < INT_MIN || num > INT_MAX)
		{
			lstclear(&a, free);
			ft_error();
		}
		add_back(&a, lstnew((int)num));
		if (check_duplicate(a) == -1)
		{
			lstclear(&a, free);
			ft_error();
		}
		i++;
	}
	return (a);
}

t_list	*build_stack(int ac, char *av[])
{
	if (ac == 2)
		return (handle_single_arg(av[1]));
	return(handle_multi_args(ac, av));
}