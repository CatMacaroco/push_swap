/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:00:53 by cmacaroc          #+#    #+#             */
/*   Updated: 2026/01/06 17:19:00 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *head)
{
	while (head != NULL && head->next != NULL)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}

void	check_error(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
	{
		ft_error();
	}
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		ft_error();
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			ft_error();
		}
		i++;
	}
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

int	check_duplicate(t_list *head)
{
	t_list	*temp;

	while (head != NULL)
	{
		temp = head->next;
		while (temp != NULL)
		{
			if (head->data == temp->data)
			{
				return (-1);
			}
			temp = temp->next;
		}
		head = head->next;
	}
	return (0);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}
