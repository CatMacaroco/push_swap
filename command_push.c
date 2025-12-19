/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:55:17 by cmacaroc          #+#    #+#             */
/*   Updated: 2025/12/16 20:23:23 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_list **a, t_list **b)
{
	if(!b || !*b)
		return;
	
	t_list *temp;
	
	a = malloc(sizeof(t_list));
	if(!a)
		return(NULL);
	
	*a->data = *b->data;
	
	temp = *a;
	*a = (*a)->next;
	
	
	
}