/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_split.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacaroc <cmacaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:55:17 by cmacaroc          #+#    #+#             */
/*   Updated: 2025/12/30 13:36:11 by cmacaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	num_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c)
		{
			i++;
		}
		if (s[i] == '\0')
		{
			break ;
		}
		count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static char	*word_dup(const char *start, size_t len)
{
	size_t	i;
	char	*substr;

	i = 0;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = start[i];
		i++;
	}
	substr[len] = '\0';
	return (substr);
}

static char	**ft_free(char **result, size_t count)
{
	while (count > 0)
		free(result[--count]);
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	count;
	char	**result;

	i = 0;
	k = 0;
	count = num_words(s, c);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!s || !result)
		return (NULL);
	while (s[i] != '\0' && k < count)
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		result[k++] = word_dup(&s[j], i - j);
		if (!result[k - 1])
			return (ft_free(result, k - 1));
	}
	result[k] = NULL;
	return (result);
}

void	ft_free_split(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free (str);
	ft_error();
}
