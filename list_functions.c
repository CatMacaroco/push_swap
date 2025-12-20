#include "push_swap.h"

t_list *lstnew(void *data)
{
	t_list *things;

	things = (t_list *)malloc(sizeof(t_list));
	if(!things)
		return(NULL);

	things->data = data;
	things->next = NULL;
	return(things);
}

void add_front_a(t_list **a, t_list *new)
{
	if(!new)
		return;
	new->next = *a;
	*a = new;
}

void add_front_b(t_list **b, t_list *new)
{
	if(!new)
		return;
	new->next = *b;
	*b = new;
}

void add_back_a(t_list **a, t_list *new)
{
	t_list *temp;

	temp = *a;

	if(!new || !a)
		return;
	if(*a == NULL)
	{
		*a = new;
		return;
	}
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
}

void add_back_b(t_list **b, t_list *new)
{
	t_list *temp;

	temp = *b;

	if(!new || !b)
		return;
	if(*b == NULL)
	{
		*b = new;
		return;
	}
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
}

int lstsize_a(t_list *a)
{
	int count = 0;

	while(a != NULL)
	{	
		count++;
		a = a->next;
	}
	return(count);
}

int lstsize_b(t_list *b)
{
	int count = 0;

	while(b != NULL)
	{	
		count++;
		b = b->next;
	}
	return(count);
}

void lstclear_a(t_list **a, void(*del)(void*))
{
	t_list *temp;

	if(!a || !*a)
		return;
	while(*a != NULL)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
}

void lstclear_b(t_list **b, void(*del)(void*))
{
	t_list *temp;

	if(!b || !*b)
		return;
	while(*b != NULL)
	{
		temp = (*b)->next;
		free(*b);
		*b = temp;
	}
}

