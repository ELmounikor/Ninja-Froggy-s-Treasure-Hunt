/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kora <mel-kora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 05:45:32 by mel-kora          #+#    #+#             */
/*   Updated: 2022/05/30 16:09:47 by mel-kora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game(char *av1)
{
	t_program	env;

	ft_putendl_fd("Reading file...", 1);
	env.map = map_getter(av1);
	ft_putendl_fd("Success...", 1);
	ft_putendl_fd("Let the game begin!", 1);
	env.steps = 0;
	env.view = 1;
	env.time = 0;
	env.flag = 0;
	env.mlx_pointer = mlx_init();
	env.width = ft_strlen(env.map[0]) * 16;
	env.height = line_count(env.map) * 16;
	env.window = mlx_new_window(env.mlx_pointer, env.width, env.height, \
	"ELmounikor Ninja Froggy's treasure hunt");
	env.pics = pic_fetcher(env.mlx_pointer);
	mlx_loop_hook(env.mlx_pointer, &game_manager, &env);
	mlx_key_hook(env.window, &move_player, &env);
	mlx_hook(env.window, 17, (1L << 17), &ft_close, &env);
	mlx_loop(env.mlx_pointer);
}

int	main(int ac, char **av)
{
	if (ac == 2 && ft_strlen(ft_strnstr(av[1], ".ber", ft_strlen(av[1]))) == 4)
		game(av[1]);
	else
		ft_error();
}
