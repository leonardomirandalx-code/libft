/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leomiran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 11:31:27 by leomiran          #+#    #+#             */
/*   Updated: 2026/11/04 22:56:41 by leomiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*temp;

	if (!lst || !del || !*lst)
		return ;
	while ((*lst)->next)
	{
		temp = *lst;
		*lst = (*lst)->next;
		del(temp->content);
		temp->next = NULL;
		free (temp);
	}
	del((*lst)->content);
	free (*lst);
	*lst = NULL;
}
