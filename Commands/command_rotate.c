/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:55:17 by cmacaroc          #+#    #+#             */
/*   Updated: 2025/12/30 13:22:51 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a, int print)
{
	t_list	*first;
	t_list	*last;

	if (!a || !*a || (*a)->next == NULL)
		return ;
	first = *a;
	*a = (*a)->next;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (print)
		ft_putstr("ra\n");
}

void	rb(t_list **b, int print)
{
	t_list	*first;
	t_list	*last;

	if (!b || !*b || (*b)->next == NULL)
		return ;
	first = *b;
	*b = (*b)->next;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (print)
		ft_putstr("rb\n");
}

void	rr(t_list **a, t_list **b, int print)
{
	ra(a, 0);
	rb(b, 0);
	if (print)
		ft_putstr("rr\n");
}
