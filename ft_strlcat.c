/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:17:10 by gopiment          #+#    #+#             */
/*   Updated: 2026/04/23 14:36:59 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	counter_one;
	size_t	counter_two;
	size_t	destiny_lenght;
	size_t	source_lenght;

	counter_one = 0;
	if (size == 0)
		return (ft_strlen(src));
	destiny_lenght = ft_strlen(dst);
	source_lenght = ft_strlen(src);
	counter_two = destiny_lenght;
	if (size <= destiny_lenght)
		return (source_lenght + size);
	while (src[counter_one] && counter_one < size - destiny_lenght - 1)
		dst[counter_two++] = src[counter_one++];
	dst[counter_two] = '\0';
	return (source_lenght + destiny_lenght);
}
