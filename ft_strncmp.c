/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:22:23 by gopiment          #+#    #+#             */
/*   Updated: 2026/04/20 13:25:49 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	counter;

	counter = 0;
	while ((s1[counter] || s2[counter]) && counter < n)
	{
		if (s1[counter] != s2[counter])
			return ((unsigned char)s1[counter] - (unsigned char)s2[counter]);
		counter++;
	}
	return (0);
}
/*
#include "libft.h"

int		main()
{
   char str1[] = "asdsa";
   char str2[] = "asdsaa";

   printf("\n%d \n",strncmp(str1, str2, 20));
   printf("%d \n",ft_strncmp(str1, str2, 20));

   printf("\n%d \n",strncmp(str1, str2, 21));
   printf("%d \n",ft_strncmp(str1, str2, 21));

   printf("\n%d \n",strncmp(str1, str2, 25));
   printf("%d \n",ft_strncmp(str1, str2, 25));

   printf("\n%d \n",strncmp(str1, str2, 19));
   printf("%d \n",ft_strncmp(str1, str2, 19));

   printf("\n%d \n",strncmp(str1, str2, 1));
   printf("%d \n",ft_strncmp(str1, str2, 1));

   printf("\n%d \n",strncmp(str1, str2, 0));
   printf("%d \n",ft_strncmp(str1, str2, 0));

   printf("\n%d \n",strncmp(str1, str2, 3));
   printf("%d \n",ft_strncmp(str1, str2, 3));

   printf("\n%d \n",strncmp(str1, str2, 2));
   printf("%d \n",ft_strncmp(str1, str2, 2));

   printf("\n%d \n",ft_strncmp(str1, str2, -1));
   printf("%d \n",ft_strncmp(str1, str2, -10));

   return(0);
}*/