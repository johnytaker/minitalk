/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:17:02 by iugolin           #+#    #+#             */
/*   Updated: 2021/10/24 15:26:00 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_lstclear(t_list **lst, void (*del)(void *))
// {
// 	t_list	*start;
// 	t_list	*p;

// 	if (!del)
// 		return ;
// 	if (lst && *lst)
// 	{
// 		start = *lst;
// 		while (start)
// 		{
// 			p = start->next;
// 			del(start->content);
// 			free(start);
// 			start = p;
// 		}
// 		*lst = NULL;
// 	}
// }

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*start;

	if (!del)
		return ;
	if (lst && *lst)
	{
		while (*lst)
		{
			del((*lst)->content);
			start = *lst;
			*lst = start->next;
			free(start);
		}
	}
}
