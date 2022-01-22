/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:55:39 by iugolin           #+#    #+#             */
/*   Updated: 2022/01/19 13:25:02 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;
	void	*ptr;
	size_t	len;

	len = count * size;
	buffer = malloc(len);
	if (!buffer)
		return (NULL);
	ptr = buffer;
	while (len--)
		*(unsigned char *)ptr++ = 0;
	return ((void *)buffer);
}
