/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:39:20 by gopiment          #+#    #+#             */
/*   Updated: 2026/04/23 15:15:21 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		counter;
	int		lenght;
	char	*pointer;

	counter = 0;
	lenght = ft_strlen(s);
	pointer = (char *)malloc((lenght + 1) * sizeof(char));
	if (!pointer)
		return (NULL);
	while (s[counter])
	{
		pointer[counter] = s[counter];
		counter++;
	}
	pointer[counter] = '\0';
	return (pointer);
}
