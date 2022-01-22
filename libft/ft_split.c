/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 02:49:59 by iugolin           #+#    #+#             */
/*   Updated: 2021/10/21 09:38:24 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static int	ft_strlen_delimiter(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s && *s != c)
	{
		count++;
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		word_len;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * words_count(s, c) + 1);
	if (!arr)
		return (NULL);
	while (*s)
	{
		if (*s && *s == c)
			s++;
		else
		{
			word_len = ft_strlen_delimiter(s, c);
			arr[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	arr[i] = NULL;
	return (arr);
}
