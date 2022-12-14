/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radan <radan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:34:59 by radan        #+#    #+#             */
/*   Updated: 2022/10/23 16:01:44 by radan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	map_init(t_map *map, t_data *data)
{
	map->spawn = 0;
	map->item = 0;
	data->t->start = clock();
	data->t->n_frame = 6;
	data->map = map;
	data->t->tmp = 1;
	data->pl->totalrots = 0;
	data->n_taken = 0;
}

void	put_text(t_data *data)
{
	char	*str;
	char	*str2;
	char	*n;
	char	*n2;

	n = ft_itoa(data->n_taken);
	n2 = ft_itoa(data->n_sprites);
	str = ft_strjoin(n, " / ");
	str2 = ft_strjoin(str, n2);
	if (data->n_taken != data->n_sprites)
		mlx_string_put(data->mlx, data->mlx_win, 800, 650, 0xffffff, str2);
	else
		mlx_string_put(data->mlx, data->mlx_win, 700, 650, 0xffffff, \
			"Good Job You Have Finished!");
	free(str);
	free(str2);
	free(n);
	free(n2);
}

int	launch_game(t_data *data)
{
	mousing(data);
	update_param(data, data->pl->rot);
	raycaster(data);
	draw_bg(data);
	minimap(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->p_img, 0, 0);
	put_text(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_map	map;

	if (ac != 2)
		return (write_error("Need exactly one parameter (./cub3D <map>.cub)"));
	data = malloc(sizeof(t_data));
	if (!data)
		exit (write_error("Error\nMalloc failed\n"));
	data->mlx = mlx_init();
	if (init_data(data))
		return (1);
	map_init(&map, data);
	if (parsing(data, &map, av))
		free_exit(data);
	mlx_mouse_move(data->mlx_win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	data->n_sprites = ft_lstsize(data->map->item);
	set_spawn(data);
	set_plane(data, data->map->dirspawn);
	mlx_mouse_hide();
	mlx_do_key_autorepeaton(data->mlx);
	mlx_hook(data->mlx_win, 2, 0, key_handler, data);
	mlx_hook(data->mlx_win, 3, 0, key_exit, data);
	mlx_hook(data->mlx_win, 17, 0, free_exit, data);
	mlx_loop_hook(data->mlx, launch_game, data);
	mlx_loop(data->mlx);
}
