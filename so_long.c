/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymoulou <aymoulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:11:12 by aymoulou          #+#    #+#             */
/*   Updated: 2022/01/09 16:14:05 by aymoulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	int	x;

	if (keycode == 2 || keycode == 124)
		to_right(&vars);
	else if (keycode == 0 || keycode == 123)
		to_left(&vars);
	else if (keycode == 13 || keycode == 126)
		to_up(&vars);
	else if (keycode == 1 || keycode == 125)
		to_down(&vars);
	else if (keycode == 53)
	{
		x = 0;
		while (vars->map[x])
		{
			free(vars->map[x]);
			x++;
		}
		free(vars->map);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(1);
	}
	return (0);
}

int	ft_exit(t_vars *v)
{
	int	x;

	x = 0;
	while (v->map[x])
	{
		free(v->map[x]);
		x++;
	}
	free(v->map);
	mlx_destroy_window(v->mlx, v->win);
	exit(1);
	return (0);
}

void	render_map(t_vars *vars)
{
	int	y1;
	int	y_map;
	int	backup_w;
	int	x1;
	int	x_map;

	y1 = 0;
	y_map = 0;
	backup_w = vars->win_w;
	while (vars->win_h > 0)
	{
		x1 = 0;
		x_map = 0;
		while (vars->win_w > 0)
		{
			put_image_to_map(vars->map[y_map][x_map], x1, y1, &vars);
			x_map++;
			x1 += 50;
			vars->win_w--;
		}
		vars->win_w = backup_w;
		y_map++;
		y1 += 50;
		vars->win_h--;
	}
}

static void	init_vars(t_vars *vars)
{
	vars->collect = 0;
	vars->movement = 0;
	vars->win_w = ft_strlen(vars->map[0]);
	vars->win_h = get_height(vars->map);
	vars->e_vars.sign = 1;
	vars->e_vars.x = 0;
	vars->e_vars.sleep = 5;
	vars->e_vars.sleep_for_move = 60;
	vars->e_vars.path_to_move = 0;
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc <= 1)
	{
		perror("\033[1;31m🛑ERROR \033[0m");
		exit(1);
	}
	(void)argv;
	check_file_is_valid(argv[1]);
	vars.map = get_map(argv[1]);
	if (vars.map != NULL)
	{
		check_map_valid(&vars);
		init_vars(&vars);
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx,
				vars.win_w * 50, vars.win_h * 50, "So-Long");
		render_map(&vars);
		mlx_hook(vars.win, 2, (1L << 0), key_hook, &vars);
		mlx_hook(vars.win, 17, (1L << 0), ft_exit, &vars);
		mlx_string_put(vars.mlx, vars.win, 5, 10, 0xffffff, "Move: 0");
		mlx_loop_hook(vars.mlx, animation, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
