/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:42:42 by iugolin           #+#    #+#             */
/*   Updated: 2022/01/19 13:35:55 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	char	*ptr;

	if (!s)
		return (NULL);
	else if (start >= ft_strlen(s))
		return (ft_strdup(""));
	else if (len >= ft_strlen(s))
		substring = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	else
		substring = (char *)malloc(sizeof(char) * len + 1);
	if (!substring)
		return (NULL);
	ptr = substring;
	s = s + start;
	len += 1;
	while (*s && len-- > 1)
		*ptr++ = *s++;
	*ptr = '\0';
	return (substring);
}
