/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:08:48 by gopiment          #+#    #+#             */
/*   Updated: 2026/04/20 13:09:03 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
		((unsigned char *)str)[counter++] = c;
	return (str);
}
/*
int main(void)
{
        char c[] = "atao";

        printf("%s", (char *)ft_memset(c, '.', 2));
}
*/
