/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kora <mel-kora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:48:29 by mel-kora          #+#    #+#             */
/*   Updated: 2022/05/27 11:08:15 by mel-kora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_count(char **map)
{
	int	count;

	count = 0;
	while (map[count])
		count++;
	return (count);
}

int	collectable_count(char **map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
			count++;
		}
	}
	return (count);
}

void	player_position(t_program *env, int *i, int *j)
{
	*i = -1;
	while ((env->map)[++*i])
	{
		*j = -1;
		while ((env->map)[*i][++*j])
		{
			if (env->map[*i][*j] == 'P' || \
			env->map[*i][*j] == 'o' || env->map[*i][*j] == 'd')
				return ;
		}
	}
}

void	step_count(t_program *env)
{
	char	*count;

	count = ft_itoa(env->steps);
	mlx_string_put(env->mlx_pointer, env->window, 0, 0, \
	0xFFFFFFFF, count);
	free(count);
}
