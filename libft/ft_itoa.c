/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 00:36:39 by iugolin           #+#    #+#             */
/*   Updated: 2021/10/22 21:09:35 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	unsigned int	len;
	unsigned int	nb;

	if (n == 0)
		return (1);
	len = 0;
	nb = n;
	if (n < 0)
	{
		nb = -n;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static void	num_to_str(char *numstr, int len, int n)
{
	unsigned int	num;

	num = n;
	if (n == 0)
		*numstr = '0';
	else if (n < 0)
	{
		num = -n;
		*numstr = '-';
	}
	*(numstr + len) = '\0';
	while (num != 0)
	{
		*(numstr + (--len)) = '0' + (num % 10);
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*numstr;
	int		len;

	len = ft_numlen(n);
	numstr = (char *)malloc(sizeof(char) * len + 1);
	if (!numstr)
		return (NULL);
	num_to_str(numstr, len, n);
	return (numstr);
}
