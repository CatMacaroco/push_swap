/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:55:17 by cmacaroc          #+#    #+#             */
/*   Updated: 2025/12/22 16:52:10 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int lstsize_a(t_list *a)
{
	int count = 0;

	while(a != NULL)
	{	
		count++;
		a = a->next;
	}
	return(count);
}

int lstsize_b(t_list *b)
{
	int count = 0;

	while(b != NULL)
	{	
		count++;
		b = b->next;
	}
	return(count);
}

void lstclear_a(t_list **a, void(*del)(void*))
{
	t_list *temp;

	if(!a || !*a)
		return;
	while(*a != NULL)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
}

void lstclear_b(t_list **b, void(*del)(void*))
{
	t_list *temp;

	if(!b || !*b)
		return;
	while(*b != NULL)
	{
		temp = (*b)->next;
		free(*b);
		*b = temp;
	}
}

