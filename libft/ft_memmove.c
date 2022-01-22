/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:48:31 by iugolin           #+#    #+#             */
/*   Updated: 2022/01/19 13:27:00 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	if (dst == src)
		return (dst);
	else if (dst < src)
	{
		while (len-- > 0)
			*temp_dst++ = *temp_src++;
	}
	else
	{
		temp_dst += len - 1;
		temp_src += len - 1;
		while (len-- > 0)
			*temp_dst-- = *temp_src--;
	}
	return (dst);
}
