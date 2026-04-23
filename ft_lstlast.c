/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:29:49 by gopiment          #+#    #+#             */
/*   Updated: 2026/04/23 18:49:36 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temporary;

	if (!lst)
		return (NULL);
	temporary = lst;
	while (temporary->next != NULL)
		temporary = temporary->next;
	return (temporary);
}
