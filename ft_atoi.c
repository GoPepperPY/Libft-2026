/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:55:07 by gopiment          #+#    #+#             */
/*   Updated: 2026/04/23 17:38:27 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	counter;
	int	saver;
	int	rest;

	rest = 0;
	saver = 1;
	counter = 0;
	while (nptr[counter] == 32 || (nptr[counter] >= 9 && nptr[counter] <= 13))
		counter++;
	if (nptr[counter] == '-' || nptr[counter] == '+')
	{
		if (nptr[counter] == '-')
			saver = -1;
		counter++;
	}
	while (nptr[counter] >= '0' && nptr[counter] <= '9')
	{
		rest = (nptr[counter] - 48) + (rest * 10);
		counter++;
	}
	return (rest * saver);
}
