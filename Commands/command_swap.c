/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:55:17 by cmacaroc          #+#    #+#             */
/*   Updated: 2025/12/30 13:22:32 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a, int print)
{
	t_list	*temp;

	if (!a || !*a || (*a)->next == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	if (print)
		ft_putstr("sa\n");
}

void	sb(t_list **b, int print)
{
	t_list	*temp;

	if (!b || !*b || (*b)->next == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = (*b)->next;
	(*b)->next = temp;
	if (print)
		ft_putstr("sb\n");
}

void	ss(t_list **a, t_list **b, int print)
{
	sa(a, 0);
	sb(b, 0);
	if (print)
		ft_putstr("ss\n");
}
