/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:00:53 by cmacaroc          #+#    #+#             */
/*   Updated: 2025/12/22 15:48:15 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_error(char *str)
{
	int i = 0;

	if(!str || !str[0])
	{
		ft_error();
		exit(EXIT_FAILURE);
	}
	while(str[i])
	{
		if(str[i] < '0' || str[i] > '9')
		{
			ft_error();
			exit(EXIT_FAILURE);
		}
		i++;
	}	
}

void check_duplicates(t_list *stack)
{
	
}