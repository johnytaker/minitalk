/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:17:14 by iugolin           #+#    #+#             */
/*   Updated: 2022/01/19 13:30:56 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	char	*ptr;
	size_t	string_size;

	string_size = ft_strlen(s1) + 1;
	s2 = (char *)malloc(sizeof(char) * string_size);
	if (!s2)
		return (NULL);
	ptr = s2;
	while (*s1)
		*ptr++ = *s1++;
	*ptr = '\0';
	return (s2);
}
