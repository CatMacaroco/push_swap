/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:36:12 by cmacaroc          #+#    #+#             */
/*   Updated: 2025/12/29 14:19:43 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_push_swap()
{
	
}

void parsing_split(char **split, t_list **a)
{
	int i;
	long num;

	i = 0;
	if(!split || !*split)
		return;
	while(split[i] != '\0')
	{
		num = ft_atol(split[i]);
		if(num < INT_MIN || num > INT_MAX || check_duplicate(*a))
		{
			lstclear(a, free);
			ft_free_split(split);
			ft_error();
		}
		add_back(a, lstnew((int)num));
		i++;
	}
	ft_free_split(split);	
}



t_list *build_stack(int ac, char *av[])
{
	t_list *a = NULL;
	char **split;
	long num;
	int i;
	
	if(ac == 2)
	{
		split = ft_split(av[1], ' ');
		parsing_split(split, &a);
	}
	else
	{
		i = 1;
		while(i < ac)
		{
			num = ft_atol(av[i]);
			if(num < INT_MIN || num > INT_MAX || check_duplicate(a))
				ft_error();
			add_back(&a, lstnew((int)num));
			i++;
		}	
	}
	return a;
}


int is_valid_number(char *str)
{
	int i;

	i = 0;
	if(str[i] == '+' || str[i] == '-')
		i++;
	if(!str[i])
		return(0);
	while(str[i])
	{
		if(str[i] < '0' || str[i] > '9')
			return(0);
		i++;
	}
	return(1);
}