/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:28:44 by gopiment          #+#    #+#             */
/*   Updated: 2026/04/23 14:32:04 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	counter_one;
	size_t	counter_two;

	counter_one = 0;
	if (!*little)
		return ((char *)big);
	if (!len)
		return (NULL);
	while (big[counter_one] && counter_one < len)
	{
		counter_two = 0;
		while (big[counter_one + counter_two]
			&& big[counter_one + counter_two] == little[counter_two]
			&& (counter_one + counter_two) < len && little[counter_two])
		{
			if (!little[counter_two + 1])
				return ((char *)&(big[counter_one]));
			counter_two++;
		}
		counter_one++;
	}
	return (0);
}
