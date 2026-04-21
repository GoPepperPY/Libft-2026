/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:09:39 by gopiment          #+#    #+#             */
/*   Updated: 2026/04/21 15:02:51 by gopiment         ###   ########.fr       */
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

/*int main(void)
{
	char c[] = "lucas";
	char y[] = "WXYZ";
	printf("%s\n", (char *)ft_memcpy(y, c, 2));
	char c1[] = "lucas";
        char y1[] = "WXYZ";

	memcpy(y1, c1, strlen(c - 3));
	printf("%lu\n", strlen(c - 3));
	printf("%s", y1);
}*/
