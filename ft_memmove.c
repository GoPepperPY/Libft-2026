/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:16:12 by gopiment          #+#    #+#             */
/*   Updated: 2026/04/23 13:57:44 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				counter;
	unsigned char		*destiny;
	unsigned char		*source;

	if (!dest && !src)
		return (NULL);
	destiny = (unsigned char *)dest;
	source = (unsigned char *)src;
	counter = -1;
	if (destiny > source)
	{
		while (n--)
			destiny[n] = source[n];
	}
	else
	{
		while (++counter < n)
			destiny[counter] = source[counter];
	}
	return (destiny);
}
