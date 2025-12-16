/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:36:12 by cmacaroc          #+#    #+#             */
/*   Updated: 2025/12/16 19:47:43 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_stack {
    int *arr;
    int top;
    int capacity;
} t_stack;

void swap_a(int ac, char *av[])
{
	int temp;
	
	if(ac == 3)
	{
		temp = av[1][0];
		av[1][0] = av[1][1];
		av[1][1] = temp;
	}
	write(1, "Error\n", 6);
}

void swap_b(int ac, char *av[])
{
	int temp;
	
	if(ac == 3)
	{
		temp = av[2][0];
		av[2][0] = av[2][1];
		av[2][1] = temp;
	}
	write(1, "Error\n", 6);
}

void swap_a_b(int ac, char *av[])
{
	int temp1;
	int temp2;
	
	if(ac == 3)
	{
		temp1 = av[2][0];
		av[2][0] = av[2][1];
		av[2][1] = temp1;
		
		temp2 = av[2][0];
		av[2][0] = av[2][1];
		av[2][1] = temp2;
	}
	write(1, "Error\n", 6);
}


typedef struct node {
    int *data;
    int index;
    struct node *next;
} 			  t_list;
