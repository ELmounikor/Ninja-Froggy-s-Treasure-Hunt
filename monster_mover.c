/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_mover.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kora <mel-kora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:31:10 by mel-kora          #+#    #+#             */
/*   Updated: 2022/05/27 11:10:02 by mel-kora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_monster(t_program **env, int i, int j)
{
	int	move;

	move = rand() % 4;
	(*env)->map[i][j] = '0';
	if (move == 0 && (*env)->map[i][j - 1] == '0')
		(*env)->map[i][j - 1] = 'M';
	else if (move == 1 && (*env)->map[i][j + 1] == '0')
		(*env)->map[i][j + 1] = 'M';
	else if (move == 2 && (*env)->map[i + 1][j] == '0')
		(*env)->map[i + 1][j] = 'M';
	else if (move == 3 && (*env)->map[i - 1][j] == '0')
		(*env)->map[i - 1][j] = 'M';
	else
		(*env)->map[i][j] = 'M';
}

void	monster(t_program *env)
{
	int	i;
	int	j;

	if (env->time % 19 == 0)
	{
		i = -1;
		while ((env->map)[++i])
		{
			j = -1;
			while ((env->map)[i][++j])
			{
				if (env->map[i][j] == 'M')
					move_monster(&env, i, j);
			}
		}
	}
}
