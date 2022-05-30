/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kora <mel-kora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 05:39:37 by mel-kora          #+#    #+#             */
/*   Updated: 2022/05/30 19:53:43 by mel-kora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check(char *input)
{
	int	flags[3];
	int	i;

	i = 0;
	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	while (input[i])
	{
		if (input[i] == 'P')
			flags[0]++;
		else if (input[i] == 'E')
			flags[1]++;
		else if (input[i] == 'C')
			flags[2]++;
		i++;
	}
	if (flags[0] == 1 && flags[1] > 0 && flags[2] > 0)
		return (1);
	return (0);
}

char	**map_getter(char *av)
{
	char	*map;
	int		fd;
	int		size;

	fd = open(av, O_RDWR);
	if (fd < 0)
		ft_error();
	size = 0;
	map = (char *) malloc (1);
	while (read(fd, map, 1))
		size++;
	close(fd);
	free(map);
	return (get_and_check(av, size));
}

char	**get_and_check(char *av, int size)
{
	char	**map;
	char	*input;
	int		fd;

	input = (char *) malloc((size + 1));
	fd = open(av, O_RDWR);
	read(fd, input, size);
	input[size] = '\0';
	map = ft_split(input, '\n');
	if (!(map && map[0] && check(input)))
		ft_error();
	close(fd);
	free(input);
	fd = 0;
	size = ft_strlen(map[fd]);
	while (map[fd] && ft_strlen(map[fd]) == size && map[fd][0] == '1' && \
	map[fd][0] == map[fd][size - 1] && !ft_strtrim(map[fd], "01CEPM"))
		fd++;
	if (map[fd] || ft_strtrim(map[fd - 1], "1") || ft_strtrim(map[0], "1"))
		ft_error();
	return (map);
}
