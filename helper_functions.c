/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:55:17 by cmacaroc          #+#    #+#             */
/*   Updated: 2025/12/29 19:11:23 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_error(void)
{
	ft_putstr("Error\n");
	return ;
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		ft_error();
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 +(str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		ft_error();
	return (result * sign);
}

// int is_valid(char **str)
// {
// 	int i;

// 	i = 0;
// 	while(str[i])
// 	{
// 		if(str[i] < '0' || str[i] > '9')
// 			return(0);
// 	}
// 	return(1);
// }
//
//
// int is_valid_size(char *str)
// {
// 	int i;
//
// 	i = 0;
// 	if (ft_atol(str) < INT_MIN || ft_atol(str) > INT_MAX)
// 		return(0);
// 	return(1);
// }

void	ft_free_split(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free (str);
	ft_error();
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
				ft_error();
			temp = temp->next;
		}
		head = head->next;
	}
	return (0);
}
