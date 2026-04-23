/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:31:55 by gopiment          #+#    #+#             */
/*   Updated: 2026/04/23 13:55:26 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t	nmemb, size_t size)
{
	void	*pointer;

	if (size != 0 && nmemb > (__SIZE_MAX__ / size))
		return (NULL);
	pointer = malloc(nmemb * size);
	if (!pointer)
		return (pointer);
	ft_bzero(pointer, size * nmemb);
	return (pointer);
}
