/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:13:08 by iugolin           #+#    #+#             */
/*   Updated: 2021/11/10 16:10:11 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s_len;
	size_t	d_len;
	size_t	i;

	s_len = ft_strlen(src);
	d_len = ft_strlen(dst);
	i = 0;
	if (d_len < dstsize)
	{
		dst += d_len;
		while (*src && (d_len + i < dstsize - 1))
		{
			*dst++ = *src++;
			i++;
		}
		*dst = '\0';
	}
	else
		d_len = dstsize;
	return (d_len + s_len);
}
