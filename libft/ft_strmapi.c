/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 02:03:34 by iugolin           #+#    #+#             */
/*   Updated: 2021/10/22 18:10:48 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s_pointer;
	unsigned int	index;

	if (!s || !f)
		return (NULL);
	s_pointer = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!s_pointer)
		return (NULL);
	index = 0;
	while (s[index])
	{
		s_pointer[index] = f(index, s[index]);
		index++;
	}
	s_pointer[index] = '\0';
	return (s_pointer);
}
