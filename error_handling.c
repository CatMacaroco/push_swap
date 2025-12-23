/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:00:53 by cmacaroc          #+#    #+#             */
/*   Updated: 2025/12/23 11:02:21 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_error(char *str)
{
	int i;
	
	i = 0;
	if(!str || !str[0])
	{
		ft_error();
	}
	if(str[i] == '+' || str[i] == '-')
		i++;
	if(str[i] == '\0')
		ft_error();
	while(str[i])
	{
		if(str[i] < '0' || str[i] > '9')
		{
			ft_error();
		}
		i++;
	}	
}

void check_duplicates(t_list *head)
{
	t_list *temp;

	temp = head;
	while(temp != NULL)
	{
		if(temp->data == temp->next->data)
		{
			ft_error();
		}
		temp = temp->next;
	}
}