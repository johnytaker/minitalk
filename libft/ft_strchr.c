/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:51:03 by iugolin           #+#    #+#             */
/*   Updated: 2021/10/22 21:39:52 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*convert_s;
	int		len;

	convert_s = (char *)s;
	len = ft_strlen(convert_s) + 1;
	while (len--)
	{
		if (*convert_s == (char)c)
			return (convert_s);
		else
			convert_s++;
	}
	return (NULL);
}
