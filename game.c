/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kora <mel-kora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:25:15 by mel-kora          #+#    #+#             */
/*   Updated: 2022/05/30 17:54:02 by mel-kora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_manager(t_program	*env)
{
	int			i;
	int			j;

	if (!collectable_count(env->map) && env->flag == 0)
	{
		i = -1;
		env->time = 14;
		while (env->map[++i])
		{
			j = -1;
			while (env->map[i][++j])
			{
				if (env->map[i][j] == 'E')
					env->map[i][j] = 'e';
			}
		}
	}
	if (env->flag >= 0)
	{
		map_drawer(env);
		monster(env);
		step_count(env);
	}
	else if (env->time == 1337 * 42 / 4)
		ft_close(env);
	return (env->time++);
}

void	losing(t_program *env)
{
	env->flag = -1;
	mlx_clear_window(env->mlx_pointer, env->window);
	ft_putendl_fd("Better luck next time...", 1);
	mlx_string_put(env->mlx_pointer, env->window, env->width / 2 - 3 * 16, \
	env->height / 2 - 16, 0xFFFFFFFF, "Game Over!");
}

void	winning(t_program *env)
{
	env->flag = -2;
	mlx_clear_window(env->mlx_pointer, env->window);
	ft_putendl_fd("You won! Congratulations!", 1);
	mlx_string_put(env->mlx_pointer, env->window, env->width / 2 - 5 * 16, \
	env->height / 2 - 1 * 16, 0xFFFFFFFF, "Congratulations!");
}

int	ft_close(t_program *env)
{
	env->flag = -1;
	clean_env(env);
	ft_putendl_fd("Closing...", 1);
	exit(0);
	return (0);
}
