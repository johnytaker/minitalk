/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:43:31 by iugolin           #+#    #+#             */
/*   Updated: 2022/01/19 13:33:31 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str_new;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	size = s1_len + s2_len + 1;
	str_new = (char *)malloc(sizeof(char) * size);
	if (!str_new)
		return (NULL);
	ft_memmove(str_new, s1, s1_len);
	ft_memmove(str_new + s1_len, s2, s2_len);
	str_new[size - 1] = '\0';
	return (str_new);
}
