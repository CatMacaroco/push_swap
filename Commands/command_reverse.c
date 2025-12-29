/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:55:17 by cmacaroc          #+#    #+#             */
/*   Updated: 2025/12/22 16:51:02 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_list **a, int print)
{
	t_list *first;
	t_list *last; 
	t_list *second_last;
	
	if(!a || !*a || (*a)->next == NULL)
		return;
	
	first = *a;
	last = *a;
	second_last = NULL;
	
	while(last->next != NULL)
	{
		second_last = last;  //[1] → [2] → [3] → [4] → NULL
            								   // ↑     ↑
           								//	second_last  last
		last = last->next;
	}
	
	second_last->next = NULL;
	last->next = first;
	*a = last;
	
	if(print)
		ft_putstr("rra\n");
}

void rrb(t_list **b, int print)
{
	t_list *first;
	t_list *last; 
	t_list *second_last;
	
	if(!b || !*b || (*b)->next == NULL)
		return;

	first = *b;
	last = *b;
	second_last = NULL;

	while(last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}

	second_last->next = NULL;
	last->next = first;
	*b = last;

	if(print)
		ft_putstr("rrb\n");
	
}

void rrr(t_list **a, t_list **b, int print)
{
	rra(a, 0);
	rrb(a, 0);

	if(print)
		ft_putstr("rrr\n");
}