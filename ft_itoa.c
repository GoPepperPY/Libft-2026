/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:57:14 by gopiment          #+#    #+#             */
/*   Updated: 2026/04/21 13:49:42 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	absolute_value(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static int	ft_digit_count(int nbr)
{
	int	counter;

	counter = 0;
	if (nbr <= 0)
		counter++;
	while (nbr != 0)
	{
		counter++;
		nbr /= 10;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		counter;

	counter = ft_digit_count(n);
	string = malloc(sizeof(char) * (counter + 1));
	if (!string)
		return (NULL);
	string[counter--] = '\0';
	if (n < 0)
		string[0] = '-';
	else if (n == 0)
		string[0] = '0';
	while (n != 0)
	{
		string[counter--] = absolute_value(n % 10) + '0';
		n /= 10;
	}
	return (string);
}
