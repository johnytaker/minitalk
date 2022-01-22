/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 00:24:57 by iugolin           #+#    #+#             */
/*   Updated: 2021/10/15 19:42:28 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	if (needle_len == 0)
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		if (*haystack == *needle && len >= needle_len)
		{
			if (ft_strncmp(haystack, needle, needle_len) == 0)
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
