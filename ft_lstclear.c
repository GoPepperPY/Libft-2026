/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:39:46 by gopiment          #+#    #+#             */
/*   Updated: 2026/04/21 11:50:39 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temporary;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temporary = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temporary;
	}
	*lst = NULL;
}
