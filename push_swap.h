/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:36:02 by cmacaroc          #+#    #+#             */
/*   Updated: 2025/12/29 19:11:55 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct node
{
	int			data;
	int			index;
	struct node	*next;
}	t_list;

// t_list	*a = NULL;
// t_list	*b = NULL;

void	pa(t_list **a, t_list **b, int print);
void	pb(t_list **a, t_list **b, int print);
void	rra(t_list **a, int print);
void	rrb(t_list **b, int print);
void	rrr(t_list **a, t_list **b, int print);
void	ra(t_list **a, int print);
void	rb(t_list **b, int print);
void	rr(t_list **a, t_list **b, int print);
void	sa(t_list **a, int print);
void	sb(t_list **b, int print);
void	ss(t_list **a, t_list **b, int print);
void	ft_putstr(char *str);
void	ft_error(void);
long	ft_atol(const char *str);
t_list	*lstnew(void *data);
void	add_front(t_list **head, t_list *new);
void	add_back(t_list **head, t_list *new);
int		lstsize(t_list *head);
void	lstclear(t_list **head, void (*del)(void*));
char	**ft_split(char const *s, char c);
t_list	*parse_args(int ac, char *av[]);
int		is_sorted(t_list *head);
void	sort_two(t_list *lst);
void	sort_three(t_list *lst, int print);
int		is_valid_size(char *str);
void	ft_free_split(char **str);
void	check_error(char *str);
int		check_duplicate(t_list *head);
void	sort_five(t_list *a, t_list *b, int print);