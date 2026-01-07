/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:36:02 by cmacaroc          #+#    #+#             */
/*   Updated: 2026/01/06 17:45:10 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
	int			data;
	int			index;
	struct node	*next;
}	t_list;

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
t_list	*lstnew(int data);
void	add_front(t_list **head, t_list *new);
void	add_back(t_list **head, t_list *new);
int		lstsize(t_list *head);
void	lstclear(t_list **head, void (*del)(void*));
char	**ft_split(char const *s, char c);
int		is_sorted(t_list *head);
void	sort_two(t_list **lst);
void	sort_three(t_list **lst);
void	ft_free_split(char **str);
void	check_error(char *str);
int		check_duplicate(t_list *head);
void	sort_five(t_list **a, t_list **b, int print);
void	assign_index(t_list **a);
int		find_minimum(t_list *lst);
int		*copy_data(t_list *stack, int size);
void	assign_indices(t_list *stack, int *sorted, int size);
void	bubble_sort(int *array, int size);
int		*copy_data(t_list *stack, int size);
t_list	*handle_single_arg(char *av);
t_list	*handle_multi_args(int ac, char *av[]);
t_list	*build_stack(int ac, char *av[]);
void	parsing_split(char **split, t_list **a);
int		main(int ac, char *av[]);
void	init_stacks(t_list **a, t_list **b, int ac, char *av[]);
void	sort_sort(t_list **a, t_list **b, int size);
void	radix_sort(t_list **a, t_list **b, int size);
int		is_valid_number(char *str);
//void	printstack(t_list *a);