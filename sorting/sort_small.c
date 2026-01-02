/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:55:17 by cmacaroc          #+#    #+#             */
/*   Updated: 2026/01/02 17:49:18 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *head)
{
	while (head != NULL && head->next != NULL)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}

void	sort_two(t_list **lst)
{
	if (is_sorted(*lst) || !*lst || !(*lst)->next)
		return ;
	sa(lst, 1);
}

void	sort_three(t_list **lst)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(*lst) || !*lst || !(*lst)->next || !(*lst)->next->next)
		return ;
	first = (*lst)->data;
	second = (*lst)->next->data;
	third = (*lst)->next->next->data;
	if (first > second && second > third)
	{
		sa(lst, 1);
		rra(lst, 1);
	}
	else if (first > second && first > third)
		ra(lst, 1);
	else if (second > first && second > third)
		rra(lst, 1);
	else if (first > second)
		sa(lst, 1);
	else
	{
		sa(lst, 1);
		ra(lst, 1);
	}
}

void	sort_five(t_list **a, t_list **b, int print)
{
	int	min_pos;
	int	rotations;

	if (is_sorted(*a) || lstsize(*a) < 4)
		return ;
	while (lstsize(*b) < 2)
	{
		min_pos = find_minimum(*a);
		if (min_pos <= lstsize(*a) / 2)
		{
			rotations = min_pos;
			while (rotations-- > 0)
				ra(a, print);
		}
		else
		{
			rotations = lstsize(*a) - min_pos;
			while (rotations-- > 0)
				rra(a, print);
		}
		pb(a, b, print);
	}
	sort_three(a);
	pa(a, b, print);
	pa(a, b, print);
}

int	find_minimum(t_list *lst)
{
	int		min;
	int		position;
	int		min_position;
	t_list	*temp;

	if (!lst)
		return (0);
	min_position = 0;
	temp = lst;
	position = 0;
	min = lst->data;
	while (temp != NULL)
	{
		if (min > temp->data)
		{
			min = temp->data;
			min_position = position;
		}
		position++;
		temp = temp->next;
	}
	return (min_position);
}

// void printstack(t_list *a)
// {
// 	while (a != NULL)
// 	{
// 		printf("%d\n", a->data);
// 		a = a->next;
// 	}
// }