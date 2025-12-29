/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:55:17 by cmacaroc          #+#    #+#             */
/*   Updated: 2025/12/29 12:52:10 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_list **a, t_list **b, int print)
{
	if(!b || !*b)
		return;
	
	t_list *temp;
	
	temp = *b;
	*b = (*b)->next; 
	temp->next = *a; 
	*a = temp;
	
	if(print)
		ft_putstr("pa\n");
	
}

void pb(t_list **a, t_list **b, int print)
{
	if(!a || !*a)
		return;
	
	t_list *temp;

	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;

	if(print)
		ft_putstr("pb\n");
}
