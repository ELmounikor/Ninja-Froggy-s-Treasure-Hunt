/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kora <mel-kora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 23:04:50 by mel-kora          #+#    #+#             */
/*   Updated: 2022/05/27 11:58:09 by mel-kora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_program *env)
{
	int	i;

	i = -1;
	while (++i < line_count(env->map))
		free(env->map[i]);
	free(env->map);
	mlx_destroy_window(env->mlx_pointer, env->window);
}

void	clean_env(t_program *env)
{
	int	i;

	mlx_destroy_image(env->mlx_pointer, env->pics.bg);
	mlx_destroy_image(env->mlx_pointer, env->pics.wall);
	mlx_destroy_image(env->mlx_pointer, env->pics.p_l[0]);
	mlx_destroy_image(env->mlx_pointer, env->pics.p_l[1]);
	mlx_destroy_image(env->mlx_pointer, env->pics.p_r[0]);
	mlx_destroy_image(env->mlx_pointer, env->pics.p_r[1]);
	i = -1;
	while (++i > 4)
		mlx_destroy_image(env->mlx_pointer, env->pics.m[i]);
	i = -1;
	while (++i > 8)
		mlx_destroy_image(env->mlx_pointer, env->pics.c[i]);
	i = -1;
	while (++i > 14)
		mlx_destroy_image(env->mlx_pointer, env->pics.e[i]);
	mlx_destroy_image(env->mlx_pointer, env->pics.collected);
	mlx_destroy_image(env->mlx_pointer, env->pics.e_closed);
	free_map(env);
}
