/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:41:18 by gopiment          #+#    #+#             */
/*   Updated: 2026/04/23 16:55:34 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*string;
	unsigned int	counter_one;
	unsigned int	counter_two;

	counter_one = start;
	counter_two = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		string = malloc(1 * sizeof(char));
		if (!string)
			return (NULL);
		string[0] = '\0';
		return (string);
	}
	string = malloc((len + 1) * sizeof(char));
	if (!string)
		return (NULL);
	while (counter_one < ft_strlen(s) && len-- > 0)
		string[counter_two++] = s[counter_one++];
	string[counter_two] = '\0';
	return (string);
}
