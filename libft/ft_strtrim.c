/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:14:25 by iugolin           #+#    #+#             */
/*   Updated: 2021/10/27 14:49:46 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_start_str(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (len > i)
	{
		if (!ft_strchr(set, s1[i]))
			break ;
		i++;
	}
	return (i);
}

static size_t	ft_get_end_str(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (len > i)
	{
		if (!ft_strchr(set, s1[len - i - 1]))
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str_new;

	if (!s1 || !set)
		return (NULL);
	start = ft_get_start_str(s1, set);
	end = ft_get_end_str(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	str_new = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str_new)
		return (NULL);
	ft_strlcpy(str_new, s1 + start, end - start + 1);
	return (str_new);
}
