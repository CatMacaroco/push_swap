/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:36:12 by cmacaroc          #+#    #+#             */
/*   Updated: 2026/01/02 19:01:31 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_list **a, t_list **b, int size)
{
	int	i;
	int	bit;
	int	max_bit;

	max_bit = 0;
	while ((1 << max_bit) < size)
		max_bit++;
	bit = 0;
	while (bit < max_bit)
	{
		i = 0;
		while (i < size)
		{
			if (((*a)->index & (1 << bit)) == 0)
				pb(a, b, 1);
			else
				ra(a, 1);
			i++;
		}
		while (*b)
			pa(a, b, 1);
		bit++;
	}
}

void	sort_sort(t_list **a, t_list **b, int size)
{
	if (is_sorted(*a))
		return ;
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size > 3 && size <= 5)
		sort_five(a, b, 1);
	else
		radix_sort(a, b, size);
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
	sort_sort(&a, &b, size);
	lstclear(&a, free);
	lstclear(&b, free);
	return (0);
}

// #include <stdio.h>
// void printstack(t_list *a)
// {
// 	while (a != NULL)
// 	{
// 		printf("%d\n", a->data);
// 		a = a->next;
// 	}
// }