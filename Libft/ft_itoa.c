/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:11:33 by mel-kora          #+#    #+#             */
/*   Updated: 2021/11/23 13:51:04 by mel-kora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_size(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size++;
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int				i;
	int				j;
	char			*output;
	unsigned int	nb;

	i = 0;
	if (n < 0)
		nb = -n;
	else
		nb = n;
	j = get_size(n);
	output = (char *) malloc ((j + 1) * sizeof(char));
	if (!output)
		return (0);
	if (n < 0)
		output[i++] = '-';
	output[j] = '\0';
	while (j-- > i)
	{
		output[j] = nb % 10 + '0';
		nb /= 10;
	}
	return (output);
}
/*
#include <stdio.h>
int	main ()
{
	int n = -2147483648;
	printf("%s", ft_itoa(n));
}*/
