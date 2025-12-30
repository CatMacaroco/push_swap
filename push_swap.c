/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:36:12 by cmacaroc          #+#    #+#             */
/*   Updated: 2025/12/30 18:24:08 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_list *a, t_list *b, int size)
{
	int	i;
	int	bit;

	bit = 0;
	while (bit < 32)
	{
		i = 0;
		while (i < size)
		{
			if ((a->index & (1 << bit)) == 0)
				pb(&a, &b, 1);
			else
				ra(&a, 1);
			i++;
		}
		while (b)
			pa(&a, &b, 1);
		bit++;
	}
}

void	parsing_split(char **split, t_list **a)
{
	int		i;
	long	num;

	i = 0;
	if (!split || !*split)
		return ;
	while (split[i] != NULL)
	{
		num = ft_atol(split[i]);
		if (num < INT_MIN || num > INT_MAX)
		{
			lstclear(a, free);
			ft_free_split(split);
			ft_error();
		}
		add_back(a, lstnew((int)num));
		if (check_duplicate(*a) == -1)
		{
			lstclear(a, free);
			ft_free_split(split);
			ft_error();
		}
		i++;
	}
	ft_free_split(split);
}

int	main(int ac, char *av[])
{
	t_list	*a;
	t_list	*b;
	int		size;

	init_stacks(&a, &b, ac, av);
	if (!a)
		return (0);
	size = lstsize(a);
	dispatch_sort(&a, b, size);
	//printstack(a);
	lstclear(&a, free);
	lstclear(&b, free);
	return (0);
}

void init_stacks(t_list **a, t_list **b, int ac, char *av[])
{
	if (ac < 2)
	{
		*a = NULL;
		*b = NULL;
		return ;
	}
	*a = build_stack(ac, av);
	*b = NULL;
	assign_index(a);
}

void	dispatch_sort(t_list **a, t_list *b, int size)
{
	if (is_sorted(*a))
		return ;
	if (size == 2)
		sort_two(a);
	if (size == 3)
		sort_three(a);
	else if (size > 3 && size <= 5)
		sort_five(*a, b, 1);
	else
		radix_sort(*a, b, size);
}
