/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:17:27 by mel-kora          #+#    #+#             */
/*   Updated: 2021/11/21 23:54:33 by mel-kora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!haystack[i] && needle[i])
		return (0);
	if (!haystack[i] || !needle[i])
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	//char haystack[] = "Salam cava bikhir shiha labas 3lik jani jo3";
	//char needle[] = "cava";
	char * empty = (char*)"";
	char *ret1 = ft_strnstr(empty, "", 2);
	char *ret2 = strnstr(empty, "", 2);
	printf("%s\n%s\n%d", ret1, ret2, ret1==ret2);
}*/
