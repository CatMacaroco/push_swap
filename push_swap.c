/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:36:12 by cmacaroc          #+#    #+#             */
/*   Updated: 2025/12/23 17:54:28 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_push_swap()
{
	
}

void parsing_split(char **split, t_list *a)
{
	int i;
	long num;

	

	i = 0;
	if(!*split || !a)
		return;
	while(split[i] != '\0')
	{
		
	}
		
}


char **split = ft_split(av[1], ' ');


int is_valid_number(char *str)
{
	int i;

	i = 0;
	if(str[i] == '+' || str[i] == '-')
		i++;
	if(!str[i])
		return(0);
	while(str[i])
	{
		if(str[i] < '0' || str[i] > '9')
			return(0);
		i++;
	}
	return(1);
}