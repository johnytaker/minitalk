/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:27:57 by iugolin           #+#    #+#             */
/*   Updated: 2021/10/22 14:54:35 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	while (*temp_s1 && (*temp_s1 == *temp_s2) && n)
	{
		temp_s1++;
		temp_s2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*temp_s1 - *temp_s2);
}
