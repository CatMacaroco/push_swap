/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing&validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:55:17 by cmacaroc          #+#    #+#             */
/*   Updated: 2025/12/22 16:55:33 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *parse_args(int ac, char *av[])
{
	int i = 0;
	
	while(ac > 1)
	{	
		ac--;
	}
	ft_error();
}

int ft_atoi(char *s)
{
	int sign = 1;
	int nb = 0;
	int i = 0;
	
	while(s[i] == ' ' || (s[i] >= 9 && s[i]<= 13))
	{
		i++;
	}
	if(s[i] == '+' || s[i] == '-')
	{
		if(s[i] == '-')
		{
			sign = -sign;
		}
		i++;
	}
	if(s[i] >= '0' && s[i] <= '9')
	{
		nb = nb * 10 + (s[i] - '0');
		i++;
	}
	return(nb * sign);
}

long ft_atol(const char *str)
{
	long result;
	int sign;
	int i;

	result = 0;
	sign = 1;
	i = 0;
	while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if(str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
			sign = -sign;
		i++;
	}
	if(str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
			sign = -sign;
		i++;
	}
	if(str[i] < '0' || str[i] > '9')
		ft_error();
	while(str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] < INT_MIN || str[i] > INT_MAX)
			ft_error();
		i++;
	}
	if(str[i] != '\0')
		ft_error();

	return(result * sign);
}

