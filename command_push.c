/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:55:17 by cmacaroc          #+#    #+#             */
/*   Updated: 2025/12/19 14:37:24 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_list **a, t_list **b)
{
	if(!b || !*b)
		return;
	
	t_list *temp;
	
	temp = *b;
	*b = (*b)->next; //head of b is now b->next(next node)
	temp->next = *a; //move a to next node
	*a = temp;			//now head of a is b.
	
	
}

void pb(t_list **a, t_list **b)
{
	if(!a || !*a)
		return;
	
	t_list *temp;

	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
}
