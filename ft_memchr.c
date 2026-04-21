/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:25:09 by gopiment          #+#    #+#             */
/*   Updated: 2026/04/20 13:25:34 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char		*str_ptr;
	int					i;

	str_ptr = (unsigned char *)str;
	i = 0;
	while (n > 0)
	{
		if (str_ptr[i] == (unsigned char)c)
			return (str_ptr + i);
		i++;
		n--;
	}
	return (NULL);
}
/*
int main ()
{
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = '/';
   char *ret;

   ret = ft_memchr(str, ch, 6);
   printf("%s \n", ret);
   printf("%s", str);

   return(0);
}*/
