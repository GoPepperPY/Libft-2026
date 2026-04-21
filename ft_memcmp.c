/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:26:11 by gopiment          #+#    #+#             */
/*   Updated: 2026/04/20 13:26:28 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	counter;
	char	*str1;
	char	*str2;

	counter = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	if (n == 0)
		return (0);
	while ((counter < n - 1) && (str1[counter] == str2[counter]))
		counter++;
	return ((unsigned char)str1[counter] - (unsigned char)str2[counter]);
}
/*
int		main()
{
   char str1[] = "acz";
   char str2[] = "";

   printf("%d \n", memcmp(str1, str2, 123));
   printf("%d", ft_memcmp(str1, str2, 123));

   return (0);
}*/
