/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:55:17 by cmacaroc          #+#    #+#             */
/*   Updated: 2025/12/22 16:51:40 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *lstnew(void *data)
{
	t_list *things;

	things = (t_list *)malloc(sizeof(t_list));
	if(!things)
		return(NULL);

	things->data = data;
	things->next = NULL;
	return(things);
}

void add_front_a(t_list **a, t_list *new)
{
	if(!new)
		return;
	new->next = *a;
	*a = new;
}

void add_front_b(t_list **b, t_list *new)
{
	if(!new)
		return;
	new->next = *b;
	*b = new;
}

void add_back_a(t_list **a, t_list *new)
{
	t_list *temp;

	temp = *a;

	if(!new || !a)
		return;
	if(*a == NULL)
	{
		*a = new;
		return;
	}
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
}

void add_back_b(t_list **b, t_list *new)
{
	t_list *temp;

	temp = *b;

	if(!new || !b)
		return;
	if(*b == NULL)
	{
		*b = new;
		return;
	}
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
}

