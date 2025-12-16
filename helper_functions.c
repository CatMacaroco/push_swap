void ft_putstr(char *str)
{
	int i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
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

int ft_error(int nb)
{
	
	return(1);
}