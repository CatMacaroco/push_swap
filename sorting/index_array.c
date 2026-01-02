/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:55:17 by cmacaroc          #+#    #+#             */
/*   Updated: 2026/01/02 17:48:47 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_data(t_list *a, int size)
{
	int		*array;
	int		i;
	t_list	*temp;

	array = malloc(sizeof(int) * size);
	if (!array)
	{
		free(a);
		ft_error();
	}
	temp = a;
	i = 0;
	while (temp)
	{
		array[i++] = temp->data;
		temp = temp->next;
	}
	return (array);
}

void	bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int	swap;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				swap = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swap;
			}
			j++;
		}
		i++;
	}
}

void	assign_indices(t_list *a, int *array, int size)
{
	t_list	*temp;
	int		i;

	temp = a;
	while (temp)
	{
		i = 0;
		while (i < size)
		{
			if (temp->data == array[i])
			{
				temp->index = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
}

void	assign_index(t_list **a)
{
	int		*array;
	int		size;

	size = lstsize(*a);
	if (size <= 1)
		return ;
	array = copy_data(*a, size);
	bubble_sort(array, size);
	assign_indices(*a, array, size);
	free(array);
}

void	init_stacks(t_list **a, t_list **b, int ac, char *av[])
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
