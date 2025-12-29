/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:55:17 by cmacaroc          #+#    #+#             */
/*   Updated: 2025/12/29 18:58:27 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lstnew(void *data)
{
	t_list	*things;

	things = (t_list *)malloc(sizeof(t_list));
	if (!things)
		return (NULL);
	things->data = data;
	things->next = NULL;
	return (things);
}

void	add_front(t_list **head, t_list *new)
{
	if (!new)
		return ;
	new->next = *head;
	*head = new;
}

void	add_back(t_list **head, t_list *new)
{
	t_list	*temp;

	temp = *head;
	if (!new || !head)
		return ;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
}

int	lstsize(t_list *head)
{
	int	count;

	count = 0;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	return (count);
}

void	lstclear(t_list **head, void (*del)(void*))
{
	t_list	*temp;

	if (!head || !*head)
		return ;
	while (*head != NULL)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
}
