/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:45:09 by gopiment          #+#    #+#             */
/*   Updated: 2026/04/23 14:37:31 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	counter_one;
	unsigned int	counter_two;
	char			*pointer;

	counter_one = 0;
	if (!s1 || !s2)
		return (NULL);
	pointer = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1 * sizeof(char));
	if (!pointer)
		return (NULL);
	while (s1[counter_one])
	{
		pointer[counter_one] = s1[counter_one];
		counter_one++;
	}
	counter_two = 0;
	while (s2[counter_two])
	{
		pointer[counter_one] = s2[counter_two];
		counter_one++;
		counter_two++;
	}
	pointer[counter_one] = '\0';
	return (pointer);
}
