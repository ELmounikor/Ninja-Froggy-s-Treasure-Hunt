/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kora <mel-kora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 05:45:28 by mel-kora          #+#    #+#             */
/*   Updated: 2022/05/30 19:56:31 by mel-kora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "Libft/Libft.h"
# include "mlx/mlx.h"
# include "math.h"

typedef struct s_pics
{
	void	*bg;
	void	*wall;
	void	*p_r[2];
	void	*p_l[2];
	void	*m[4];
	void	*c[8];
	void	*collected;
	void	*e_closed;
	void	*e[14];
}	t_pics;

typedef struct s_program
{
	void	*mlx_pointer;
	void	*window;
	int		width;
	int		height;
	char	**map;
	int		steps;
	int		view;
	int		time;
	int		flag;
	t_pics	pics;
}	t_program;

void	game(char *av1);
/*error management functions*/
char	**get_and_check(char *av, int size);
char	**map_getter(char *av);
/*game management functions*/
int		game_manager(t_program	*env);
int		move_player(int keycode, t_program	*env);
void	monster(t_program *env);
void	winning(t_program *env);
void	losing(t_program *env);
int		ft_close(t_program *env);
/*display functions*/
t_pics	pic_fetcher(void *mlx);
void	map_drawer(t_program	*env);
void	*draw_it(t_program *env, char c);
void	*open_door(t_program *env);
/*counting functions*/
void	step_count(t_program *env);
int		line_count(char **map);
int		collectable_count(char **map);
void	player_position(t_program *env, int *i, int *j);
/*cleaning function*/
void	clean_env(t_program *env);
#endif