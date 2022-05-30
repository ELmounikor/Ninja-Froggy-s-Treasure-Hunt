/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kora <mel-kora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:29:19 by mel-kora          #+#    #+#             */
/*   Updated: 2022/05/27 11:21:49 by mel-kora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*open_door(t_program *env)
{
	if (env->flag != 13)
	{
		env->flag = (env->time / 5) % 14 + 1;
		return (env->pics.e[env->flag - 1]);
	}
	return (env->pics.e[13]);
}

void	exit_pic_fetcher(void *mlx, t_pics *pics)
{
	int		dim[2];

	pics->e_closed = mlx_xpm_file_to_image(mlx, "assets/E/cl.xpm", dim, \
	dim + 1);
	pics->e[0] = mlx_xpm_file_to_image(mlx, "assets/E/d0.xpm", dim, dim + 1);
	pics->e[1] = mlx_xpm_file_to_image(mlx, "assets/E/d1.xpm", dim, dim + 1);
	pics->e[2] = mlx_xpm_file_to_image(mlx, "assets/E/d2.xpm", dim, dim + 1);
	pics->e[3] = mlx_xpm_file_to_image(mlx, "assets/E/d3.xpm", dim, dim + 1);
	pics->e[4] = mlx_xpm_file_to_image(mlx, "assets/E/d4.xpm", dim, dim + 1);
	pics->e[5] = mlx_xpm_file_to_image(mlx, "assets/E/d5.xpm", dim, dim + 1);
	pics->e[6] = mlx_xpm_file_to_image(mlx, "assets/E/d6.xpm", dim, dim + 1);
	pics->e[7] = mlx_xpm_file_to_image(mlx, "assets/E/d7.xpm", dim, dim + 1);
	pics->e[8] = mlx_xpm_file_to_image(mlx, "assets/E/d8.xpm", dim, dim + 1);
	pics->e[9] = mlx_xpm_file_to_image(mlx, "assets/E/d9.xpm", dim, dim + 1);
	pics->e[10] = mlx_xpm_file_to_image(mlx, "assets/E/d10.xpm", dim, dim + 1);
	pics->e[11] = mlx_xpm_file_to_image(mlx, "assets/E/d11.xpm", dim, dim + 1);
	pics->e[12] = mlx_xpm_file_to_image(mlx, "assets/E/d12.xpm", dim, dim + 1);
	pics->e[13] = mlx_xpm_file_to_image(mlx, "assets/E/d13.xpm", dim, dim + 1);
}

t_pics	pic_fetcher(void *mlx)
{
	t_pics	pics;
	int		dim[2];

	pics.bg = mlx_xpm_file_to_image(mlx, "assets/O/brown.xpm", dim, dim + 1);
	pics.wall = mlx_xpm_file_to_image(mlx, "assets/O/wall.xpm", dim, dim + 1);
	pics.p_r[0] = mlx_xpm_file_to_image(mlx, "assets/P/R0.xpm", dim, dim + 1);
	pics.p_r[1] = mlx_xpm_file_to_image(mlx, "assets/P/R1.xpm", dim, dim + 1);
	pics.p_l[0] = mlx_xpm_file_to_image(mlx, "assets/P/L0.xpm", dim, dim + 1);
	pics.p_l[1] = mlx_xpm_file_to_image(mlx, "assets/P/L1.xpm", dim, dim + 1);
	pics.m[0] = mlx_xpm_file_to_image(mlx, "assets/M/M0.xpm", dim, dim + 1);
	pics.m[1] = mlx_xpm_file_to_image(mlx, "assets/M/M1.xpm", dim, dim + 1);
	pics.m[2] = mlx_xpm_file_to_image(mlx, "assets/M/M2.xpm", dim, dim + 1);
	pics.m[3] = mlx_xpm_file_to_image(mlx, "assets/M/M3.xpm", dim, dim + 1);
	pics.c[0] = mlx_xpm_file_to_image(mlx, "assets/C/C0.xpm", dim, dim + 1);
	pics.c[1] = mlx_xpm_file_to_image(mlx, "assets/C/C1.xpm", dim, dim + 1);
	pics.c[2] = mlx_xpm_file_to_image(mlx, "assets/C/C2.xpm", dim, dim + 1);
	pics.c[3] = mlx_xpm_file_to_image(mlx, "assets/C/C3.xpm", dim, dim + 1);
	pics.c[4] = mlx_xpm_file_to_image(mlx, "assets/C/C4.xpm", dim, dim + 1);
	pics.c[5] = mlx_xpm_file_to_image(mlx, "assets/C/C5.xpm", dim, dim + 1);
	pics.c[6] = mlx_xpm_file_to_image(mlx, "assets/C/C6.xpm", dim, dim + 1);
	pics.c[7] = mlx_xpm_file_to_image(mlx, "assets/C/C7.xpm", dim, dim + 1);
	pics.collected = mlx_xpm_file_to_image(mlx, "assets/C/c.xpm", dim, dim + 1);
	exit_pic_fetcher(mlx, &pics);
	return (pics);
}

void	*draw_it(t_program *env, char c)
{
	if (c == '0')
		return (env->pics.bg);
	if (c == '1')
		return (env->pics.wall);
	if (c == 'P' || c == 'o' || c == 'd')
	{
		if (env->view == 1)
			return (env->pics.p_r[env->steps % 2]);
		if (env->view == -1)
			return (env->pics.p_l[env->steps % 2]);
	}
	if (c == 'M')
		return (env->pics.m[(env->time / 10) % 4]);
	if (c == 'C')
		return (env->pics.c[(env->time / 5) % 8]);
	if (c == 'c')
		return (env->pics.collected);
	if (c == 'E')
		return (env->pics.e_closed);
	if (c == 'e')
		return (open_door(env));
	return (0);
}

void	map_drawer(t_program	*env)
{
	int			i;
	int			j;

	i = -1;
	mlx_clear_window(env->mlx_pointer, env->window);
	while (++i * 16 < env->height)
	{
		j = -1;
		while (++j * 16 < env->width)
		{
			if (env->map[i][j] != 0 && env->map[i][j] != 1)
				mlx_put_image_to_window(env->mlx_pointer, env->window, \
				env->pics.bg, j * 16, i * 16);
			if (env->map[i][j] == 'o')
				mlx_put_image_to_window(env->mlx_pointer, env->window, \
				env->pics.collected, j * 16, i * 16);
			if (env->map[i][j] == 'd')
				mlx_put_image_to_window(env->mlx_pointer, env->window, \
				env->pics.e_closed, j * 16, i * 16);
			mlx_put_image_to_window(env->mlx_pointer, env->window, \
			draw_it(env, env->map[i][j]), j * 16, i * 16);
		}
	}
}
