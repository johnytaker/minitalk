/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:32:56 by iugolin           #+#    #+#             */
/*   Updated: 2021/10/12 17:36:52 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	convert_c;
	char	*convert_s;

	convert_c = (char)c;
	convert_s = (char *)s + ft_strlen(s);
	while (convert_s >= s)
	{
		if (*convert_s == convert_c)
			return (convert_s);
		convert_s--;
	}
	return (NULL);
}
