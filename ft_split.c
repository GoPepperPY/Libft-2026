/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:54:27 by gopiment          #+#    #+#             */
/*   Updated: 2026/04/20 13:56:19 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	counter;
	int	trigger;

	counter = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			counter++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (counter);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		counter;

	counter = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[counter++] = str[start++];
	word[counter] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	counter_1;
	size_t	counter_2;
	int		index;
	char	**split;

	if (!s)
		return (0);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (0);
	counter_1 = -1;
	counter_2 = 0;
	index = -1;
	while (++counter_1 <= ft_strlen(s))
	{
		if (s[counter_1] != c && index < 0)
			index = counter_1;
		else if ((s[counter_1] == c || counter_1 == ft_strlen(s)) && index >= 0)
		{
			split[counter_2++] = word_dup(s, index, counter_1);
			index = -1;
		}
	}
	split[counter_2] = 0;
	return (split);
}
/*
int main(void)
{
	char	*str = "Goncalo Pimenta";
	char	sep = ' ';
	char	**result = ft_split(str, sep);
	int		counter;

	counter = 0;
	while (result[counter])
	{
		puts(result[counter]);
		counter++;
	}
	return (0);
}
*/