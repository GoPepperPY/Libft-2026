/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:21:05 by gopiment          #+#    #+#             */
/*   Updated: 2026/04/21 11:56:34 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*temporary;
	int		counter;

	counter = 0;
	temporary = (char *)s;
	while (s[counter] != c)
	{
		if (!s[counter])
			return (NULL);
		temporary++;
		counter++;
	}
	return (temporary);
}
