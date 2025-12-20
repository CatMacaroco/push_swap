/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:55:17 by cmacaroc          #+#    #+#             */
/*   Updated: 2025/12/20 15:04:10 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_putstr(char *str)
{
	int i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void ft_putnbr(int nb)
{
	char c;
	if(nb > 9)
		ft_putnbr(nb/10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}

int ft_atoi(char *s)
{
	int nb = 0;
	int i = 0;
	int sign = 1;

	while(s[i] == ' ' || s[i] == 9)
		i++;
	if(s[i] == '+' || s[i] == '-')
	{
		if(s[i] == '-')
			sign = -sign;
		i++;
	}
	while(s[i] >= '0' && s[i] <= '9')
	{
		nb = nb * 10 + (s[i] - '0');
		i++;
	}
	return(nb * sign);
}

void ft_error()
{
	ft_putstr("ERROR\n");
	return;
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