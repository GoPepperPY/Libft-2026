/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:32:19 by gopiment          #+#    #+#             */
/*   Updated: 2026/04/23 19:06:07 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temporary;

	if (!new)
		return ;
	temporary = ft_lstlast(*lst);
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temporary->next = new;
}
