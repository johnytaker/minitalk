/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:40:16 by iugolin           #+#    #+#             */
/*   Updated: 2021/10/22 23:28:28 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_elem;

	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			last_elem = ft_lstlast(*lst);
			last_elem->next = new;
		}
	}
}
