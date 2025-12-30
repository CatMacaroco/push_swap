/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:55:17 by cmacaroc          #+#    #+#             */
/*   Updated: 2025/12/30 19:20:51 by cmacaroc         ###   ########.fr       */
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
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
			}
			j++;
		}
		i++;
	}
}

void	assign_indices(t_list *stack, int *array, int size)
{
	t_list	*temp;
	int		i;

	temp = stack;
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
