/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing&validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:55:17 by cmacaroc          #+#    #+#             */
/*   Updated: 2025/12/22 15:07:21 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *parse_args(int ac, char *av[])
{
	int i = 0;
	
	if(ac > 2)
	{
		
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

long ft_atol(const char *str, int *error)
{
	long result = 0;
	int sign = 1;
	int i = 0;
	int digit;
	
	*error = 0;

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
		return(*error = 1, 0);
	while(str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i] - '0';

		if(sign == 1 && (result > (INT_MAX - digit) / 10))
			return(*error = 1, 0);
		if(sign == -1 && (-result < (INT_MIN + digit) / 10))
			return(*error = 1, 0);

		result = result * 10 + digit;
		i++;
	}
	if(str[i] != '\0')
		return(*error = 1, 0);

	return(result * sign);
}