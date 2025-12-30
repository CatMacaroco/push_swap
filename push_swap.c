/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:36:12 by cmacaroc          #+#    #+#             */
/*   Updated: 2025/12/30 13:33:33 by cmacaroc         ###   ########.fr       */
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
				pb(a, b, 1);
			else
				ra(a, 1);
			i++;
		}
		while (b)
			pa(a, b, 1);
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

t_list	*build_stack(int ac, char *av[])
{
	t_list	*a;
	char	**split;
	long	num;
	int		i;

	a = NULL;
	if (ac == 2)
	{
		split = ft_split(av[1], ' ');
		parsing_split(split, &a);
	}
	else
	{
		i = 1;
		while (i < ac)
		{
			num = ft_atol(av[i]);
			if (num < INT_MIN || num > INT_MAX || check_duplicate(a))
				ft_error();
			add_back(&a, lstnew((int)num));
			i++;
		}
	}
	return (a);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	t_list	*a;
	t_list	*b;
	int		size;

	if (ac < 2)
		return (0);
	a = build_stack(ac, av);
	b = NULL;
	if (is_sorted(a))
		return (0);
	size = lstsize(a);
	if (size == 2)
		sort_two(a);
	if (size == 3)
		sort_three(a, 1);
	else if (size > 3 && size <= 5)
		sort_five(a, b, 1);
	else
		radix_sort(a, b, size);
	lstclear(&a, free);
	lstclear(&b, free);
	return (0);
}
