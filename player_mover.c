/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mover.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kora <mel-kora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:46:43 by mel-kora          #+#    #+#             */
/*   Updated: 2022/05/30 17:46:01 by mel-kora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_program **env, int i, int j)
{
	(*env)->view = -1;
	if ((*env)->map[i][j - 1] != '1')
	{
		(*env)->steps++;
		if ((*env)->map[i][j] == 'P')
			(*env)->map[i][j] = '0';
		else if ((*env)->map[i][j] == 'o')
			(*env)->map[i][j] = 'c';
		else if ((*env)->map[i][j] == 'd')
			(*env)->map[i][j] = 'E';
		if ((*env)->map[i][j - 1] == 'C' || (*env)->map[i][j - 1] == 'c')
			(*env)->map[i][j - 1] = 'o';
		else if ((*env)->map[i][j - 1] == 'E')
			(*env)->map[i][j - 1] = 'd';
		else if ((*env)->map[i][j - 1] == '0')
			(*env)->map[i][j - 1] = 'P';
		else if ((*env)->map[i][j - 1] == 'e' || (*env)->map[i][j - 1] == 'M')
		{
			(*env)->time = 0;
			if ((*env)->map[i][j - 1] == 'e')
				winning(*env);
			else if ((*env)->map[i][j - 1] == 'M')
				losing(*env);
		}
	}
}

void	move_right(t_program **env, int i, int j)
{
	(*env)->view = 1;
	if ((*env)->map[i][j + 1] != '1')
	{
		(*env)->steps++;
		if ((*env)->map[i][j] == 'P')
			(*env)->map[i][j] = '0';
		else if ((*env)->map[i][j] == 'o')
			(*env)->map[i][j] = 'c';
		else if ((*env)->map[i][j] == 'd')
			(*env)->map[i][j] = 'E';
		if ((*env)->map[i][j + 1] == 'C' || (*env)->map[i][j + 1] == 'c')
			(*env)->map[i][j + 1] = 'o';
		else if ((*env)->map[i][j + 1] == 'E')
			(*env)->map[i][j + 1] = 'd';
		else if ((*env)->map[i][j + 1] == '0')
			(*env)->map[i][j + 1] = 'P';
		else if ((*env)->map[i][j + 1] == 'e' || (*env)->map[i][j + 1] == 'M')
		{
			(*env)->time = 0;
			if ((*env)->map[i][j + 1] == 'e')
				winning(*env);
			else if ((*env)->map[i][j + 1] == 'M')
				losing(*env);
		}
	}
}

void	move_up(t_program **env, int i, int j)
{
	if ((*env)->map[i - 1][j] != '1')
	{
		(*env)->steps++;
		if ((*env)->map[i][j] == 'P')
			(*env)->map[i][j] = '0';
		else if ((*env)->map[i][j] == 'o')
			(*env)->map[i][j] = 'c';
		else if ((*env)->map[i][j] == 'd')
			(*env)->map[i][j] = 'E';
		if ((*env)->map[i - 1][j] == 'C' || (*env)->map[i - 1][j] == 'c')
			(*env)->map[i - 1][j] = 'o';
		else if ((*env)->map[i - 1][j] == 'E')
			(*env)->map[i - 1][j] = 'd';
		else if ((*env)->map[i - 1][j] == '0')
			(*env)->map[i - 1][j] = 'P';
		else if ((*env)->map[i - 1][j] == 'e' || (*env)->map[i - 1][j] == 'M')
		{
			(*env)->time = 0;
			if ((*env)->map[i - 1][j] == 'e')
				winning(*env);
			else if ((*env)->map[i - 1][j] == 'M')
				losing(*env);
		}
	}
}

void	move_down(t_program **env, int i, int j)
{
	if ((*env)->map[i + 1][j] != '1')
	{
		(*env)->steps++;
		if ((*env)->map[i][j] == 'P')
			(*env)->map[i][j] = '0';
		if ((*env)->map[i][j] == 'o')
			(*env)->map[i][j] = 'c';
		if ((*env)->map[i][j] == 'd')
			(*env)->map[i][j] = 'E';
		if ((*env)->map[i + 1][j] == 'C' || (*env)->map[i + 1][j] == 'c')
			(*env)->map[i + 1][j] = 'o';
		if ((*env)->map[i + 1][j] == 'E')
			(*env)->map[i + 1][j] = 'd';
		if ((*env)->map[i + 1][j] == '0')
			(*env)->map[i + 1][j] = 'P';
		else if ((*env)->map[i + 1][j] == 'e' || (*env)->map[i + 1][j] == 'M')
		{
			(*env)->time = 0;
			if ((*env)->map[i + 1][j] == 'e')
				winning(*env);
			if ((*env)->map[i + 1][j] == 'M')
				losing(*env);
		}
	}
}

int	move_player(int keycode, t_program	*env)
{
	int	i;
	int	j;

	if (env->flag >= 0)
	{
		player_position(env, &i, &j);
		if (keycode == 13 || keycode == 126 || keycode == 91)
			move_up(&env, i, j);
		else if (keycode == 1 || keycode == 125 || keycode == 84)
			move_down(&env, i, j);
		else if (keycode == 0 || keycode == 123 || keycode == 86)
			move_left(&env, i, j);
		else if (keycode == 2 || keycode == 124 || keycode == 88)
			move_right(&env, i, j);
	}
	if (keycode == 53)
		ft_close(env);
	return (env->time);
}
