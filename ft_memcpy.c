/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:09:39 by gopiment          #+#    #+#             */
/*   Updated: 2026/04/23 13:57:40 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	counter;

	if (!dest && !src)
		return (NULL);
	counter = 0;
	while (counter < n)
	{
		((char *)dest)[counter] = ((char *)src)[counter];
		counter++;
	}
	return (dest);
}
