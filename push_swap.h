/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:36:02 by cmacaroc          #+#    #+#             */
/*   Updated: 2025/12/22 14:20:18 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct node {
    int *data;
    int index;
    struct node *next;
} 			  t_list;

t_list *a = NULL;
t_list *b = NULL;

void pa(t_list **a, t_list **b);
void pb(t_list **a, t_list **b);
void rra(t_list **a, int print);
void rrb(t_list **b, int print);
void rrr(t_list **a, t_list **b, int print);
void ra(t_list **a, int print);
void rb(t_list **b, int print);
void rr(t_list **a, t_list **b, int print);
void sa(t_list **a, int print);
void sb(t_list **b, int print);
void ss(t_list **a, t_list **b, int print);
void ft_putstr(char *str);
void ft_putnbr(int nb);
int ft_atoi(char *s);
void ft_error();
t_list *lstnew(void *data);
void add_front_a(t_list **a, t_list *new);
void add_front_b(t_list **b, t_list *new);
void add_back_a(t_list **a, t_list *new);
void add_back_b(t_list **b, t_list *new);
int lstsize_a(t_list *a);
int lstsize_b(t_list *b);
void lstclear_a(t_list **a, void(*del)(void*));
void lstclear_b(t_list **b, void(*del)(void*));