/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_big.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:55:17 by cmacaroc          #+#    #+#             */
/*   Updated: 2025/12/30 17:34:45 by cmacaroc         ###   ########.fr       */
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
	int	min_pos;

	if (is_sorted(*lst) || !*lst || !(*lst)->next || !(*lst)->next->next)
		return ;
	min_pos = find_minimum(*lst);
	if (min_pos == 1)
	{
		sa(lst, 1);
		rra(lst, 1);
	}
	else if (min_pos == 2)
		ra(lst, 1);
	if (!is_sorted(*lst))
		sa(lst, 1);
}

void	sort_five(t_list *a, t_list *b, int print)
{
	int	size;
	int	min_pos;

	size = lstsize(a);
	if (is_sorted(a) || size < 3 || size > 5)
		return ;
	while (lstsize(b) < 2)
	{
		min_pos = find_minimum(a);
		if (min_pos <= lstsize(a) / 2)
			while (min_pos--)
				ra(&a, print);
		else
			while (min_pos--)
				rra(&a, print);
		pb(&a, &b, print);
	}
	sort_three(&a);
	pa(&a, &b, print);
	pa(&a, &b, print);
}

int	find_minimum(t_list *lst)
{
	int		min;
	int		position;
	int		min_position;
	t_list	*temp;

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