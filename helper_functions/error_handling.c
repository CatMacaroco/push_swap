/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:00:53 by cmacaroc          #+#    #+#             */
/*   Updated: 2026/01/02 17:30:19 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_putstr("Error\n");
	exit (1);
}
