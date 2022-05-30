/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kora <mel-kora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 21:23:10 by mel-kora          #+#    #+#             */
/*   Updated: 2022/04/25 05:06:38 by mel-kora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	arraysize(char const *s, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] == c)
			size++;
		i++;
	}
	return (size + 1);
}

static int	*wordsizes(char const *s, char c)
{
	int	i;
	int	j;
	int	size;
	int	*sizes;

	i = 0;
	size = arraysize(s, c);
	sizes = (int *) malloc((size + 1) * sizeof(int));
	if (!sizes)
		return (0);
	j = 0;
	while (s[i] && j < size)
	{
		sizes[j] = 0;
		while (s[i] && s[i] != c)
		{
			sizes[j]++;
			i++;
		}
		i++;
		j++;
	}
	return (sizes);
}

static char	**allocation(char const *s, char c)
{
	char	**output;
	int		size;
	int		*sizes;
	int		i;

	size = arraysize(s, c);
	output = (char **) malloc((size + 1) * sizeof(char *));
	if (!output || !s)
		return (0);
	i = 0;
	sizes = wordsizes(s, c);
	while (i < size)
	{
		output[i] = (char *) malloc((sizes[i] + 1) * sizeof(char));
		if (!output[i])
		{
			while (i--)
				free(output[i]);
			free(output);
			return (0);
		}
		i++;
	}
	free(sizes);
	return (output);
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	int		*sizes;
	int		i;
	int		j;
	int		k;

	output = allocation(s, c);
	if (!output)
		return (0);
	i = 0;
	k = 0;
	sizes = wordsizes(s, c);
	while (i < arraysize(s, c))
	{
		j = 0;
		while (j < sizes[i] && s[k] != c)
			output[i][j++] = s[k++];
		output[i++][j] = '\0';
		k++;
	}
	output[i] = NULL;
	free(sizes);
	return (output);
}
/*
int    main()
{
	char s[100] = ",, ,mou,nia,el,kora,ichi, ,,mop,";
	char c = ',';
	int  i = 0;
	char **array = ft_split(s, c);
	while(array[i])
		printf("'%s'\n", array[i++]);
	system("leaks a.out");
}*/