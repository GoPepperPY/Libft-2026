/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:41:18 by gopiment          #+#    #+#             */
/*   Updated: 2026/04/20 14:47:41 by gopiment         ###   ########.fr       */
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
		if (string == NULL)
			return (NULL);
		string[0] = '\0';
		return (string);
	}
	string = malloc((len + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	while (counter_one < ft_strlen(s) && len-- > 0)
		string[counter_two++] = s[counter_one++];
	string[counter_two] = '\0';
	return (string);
}
/*
int	main(void)
{
	char str[] = "Esta eh a string que vou passar.";
	char *asd;
	int start = 2;
	int length = 5;

	printf("%s\n", str);
	asd = ft_substr(str, start, length);
	printf("%s\n", asd);

	return (0);
}*/