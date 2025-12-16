// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   push_swap.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/12/02 15:36:12 by cmacaroc          #+#    #+#             */
// /*   Updated: 2025/12/03 17:10:25 by cmacaroc         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

 #include "push_swap.h"
 #include <stdlib.h>
 #include <stdio.h>

int main()
{

	t_list *begin_list;
	begin_list = malloc(sizeof(t_list));
	if(!begin_list)
		return(NULL);
	begin_list->data = 3;
	begin_list->next = NULL;

	t_list *begin_list_second;
	begin_list_second = malloc(sizeof(t_list));
	if(!begin_list_second)
		return(NULL);
	begin_list_second->data = 7;
	begin_list_second->next = NULL;
	begin_list->next = begin_list_second;


	t_list *begin_list_third;
	begin_list_third = malloc(sizeof(t_list));
	if(!begin_list_third)
		return NULL;
	begin_list_third->data = 8;
	begin_list_third->next = NULL;
	begin_list->next->next = begin_list_third;
}


typedef struct node {
    int *data;
    int index;
    struct node *next;
} 			  t_list;
