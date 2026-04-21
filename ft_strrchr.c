/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:21:36 by gopiment          #+#    #+#             */
/*   Updated: 2026/04/20 13:21:55 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*last;

	last = 0;
	if (c == '\0')
		return ((char *)str + ft_strlen(str));
	while (*str)
	{
		if (*str == c)
		{
			last = ((char *)str);
		}
		str++;
	}
	return (last);
}
/*
int		main()
{
	char a[] = "Olua, quem faula?";
	char b = 'u';

	char c[] = "Olua, quem faula?";
	char d = 'u';

	printf("%s\n", strrchr(a, b));

	printf("\n%s\n", ft_strrchr(c, d));

	return (0);
}*/
