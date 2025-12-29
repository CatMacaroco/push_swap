/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_big.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:55:17 by cmacaroc          #+#    #+#             */
/*   Updated: 2025/12/29 12:57:37 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_list *head)
{
	while(head != NULL && head->next != NULL)
	{
		if(head->data > head->next->data)
			return(0);
		head = head->next;
	}
	return(1);
}

void sort_two(t_list *lst)
{
	if(is_sorted(lst))
		return;
	int temp;
	if(!lst || !lst->next)
		return;
	if(lst->data > lst->next->data)
	{
		temp = lst->data;
		lst->data = lst->next->data;
		lst->next->data = temp;
	}
	ft_putstr("sa\n");
}

void sort_three(t_list *lst, int print)
{
	if(is_sorted(lst))
		return;
		
	t_list *head;
	
	head = lst;
	if(!lst || !lst->next)
		return;
	
	if(lst->data > lst->next->data)
		sa(lst, 1);
	else if(lst->data > lst->next->data && lst->data > lst->next->next->data)
		ra(lst, 1);
	else if(lst->data > lst->next->data && lst->next->data < lst->next->next->data)
		ra(lst, 1);
	else if(lst->next->data > lst->next->next->data && lst->next->data > lst->data)
	{
		sa(lst, 1);
		ra(lst, 1);
	}
	else if(lst->data < lst->next->data && lst->data > lst->next->next->data)
		rra(lst, 1);
}

int find_minimum(t_list *lst)
{
	int min;
	int position;
	int min_position;
	t_list *temp;

	min_position = 0;
	temp = lst;
	position = 0;
	min = lst->data;

	while(temp != NULL)
	{
		if(min > temp->next->data)
		{
			min = temp->next->data;
			min_position = position;
		}
		position++;
		temp = temp->next;
	}
	return(min_position);
}

int check_duplicate(t_list *head)
{
	t_list *temp;
	
	while(head != NULL)
	{
		temp = head->next;
		while(temp != NULL)
		{
			if(head->data == temp->data)
				ft_error();
			temp = temp->next;
		}
		head = head->next;
	}
	return(0);
}


// void printstack(t_list *a)
// {
// 	while (a != NULL)
// 	{
// 		printf("%d\n", a->data);
// 		a = a->next;
// 	}
// }

int main()
{
	t_list *catarina;

	catarina = malloc(sizeof(t_list));
	if(!catarina)
		return(0);
	catarina->data = 5;
	catarina->next = NULL;
	
	t_list *cat;

	cat = malloc(sizeof(t_list));
	if(!cat)
		return(0);
	cat->data = 2;
	cat->next = NULL;

	catarina->next = cat;

	sort_small_stack(catarina);
	
	printstack(catarina);
	
}

