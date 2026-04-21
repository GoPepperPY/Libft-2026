/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:52:20 by gopiment          #+#    #+#             */
/*   Updated: 2026/04/21 13:25:59 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		end;
	int		start;

	start = -1;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1) - 1;
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) - 1));
	ft_strlcpy(new, s1, end);
	while(ft_strchr(set, s1[++start]) && new)
		new++;
	while(ft_strchr(set, s1[end] && new))
		end--;
	new[end] = '\0';
	return(new);
}

// int	main(void)
// {
// 	char	*str = "uLucas Henriqueu";
// 	char	*set = "ueLi";
// 	printf("%s", "str = ");
// 	printf("%s\n", str);
// 	printf("%s", "set = ");
// 	printf("%s\n\n", set);
// 	printf("%s", "ft_strtrim = ");
// 	printf("%s\n", ft_strtrim(str, set));
// 	return (0);
// }