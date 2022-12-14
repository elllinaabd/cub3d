/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radan <radan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:42:05 by radan        #+#    #+#             */
/*   Updated: 2022/10/26 11:45:20 by radan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	set_plane(t_data *ptr, char flag)
{
	if (flag == 'W')
	{
		ptr->pl->plx = -0.66;
		ptr->pl->diry = -1;
	}
	else if (flag == 'E')
	{
		ptr->pl->plx = 0.66;
		ptr->pl->diry = 1;
	}
	else if (flag == 'N')
	{
		ptr->pl->ply = 0.66;
		ptr->pl->dirx = -1;
	}
	else if (flag == 'S')
	{
		ptr->pl->ply = -0.66;
		ptr->pl->dirx = 1;
	}
}

void	init_texture(t_data *ptr, int flag, char *path)
{
	ptr->img[flag]->p_img = mlx_xpm_file_to_image(ptr->mlx, \
		path, &ptr->img[flag]->width, &ptr->img[flag]->height);
	if (!(ptr->img[flag]->p_img))
		exit(write_error("Error\nMap load\n"));
	ptr->img[flag]->p_img = mlx_get_data_addr(ptr->img[flag]->p_img, \
		&ptr->img[flag]->bt, &ptr->img[flag]->s_line, &ptr->img[flag]->endian);
}

int	init_data(t_data *data)
{
	int	i;

	i = 0;
	data->mlx_win = mlx_new_window(data->mlx, WIN_WIDTH, \
		WIN_HEIGHT, "cub3d");
	data->p_img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->pl = malloc(sizeof(t_player));
	data->dda = malloc(sizeof(t_dda));
	data->t = malloc(sizeof(t_time));
	data->img = malloc(sizeof(t_img *) * 17);
	if (!data->mlx || !data->mlx_win || !data->pl
		|| !data->dda || !data->t || !data->img)
		return (1);
	while (i <= 16)
	{
		data->img[i] = malloc(sizeof(t_img));
		if (!data->img[i])
			return (1);
		i++;
	}
	data->sp = malloc(sizeof(t_sprite));
	data->sp->buffer = malloc(sizeof(double) * (WIN_WIDTH + 1));
	data->img[0]->p_img = mlx_get_data_addr(data->p_img, &data->img[0]->bt, \
			&data->img[0]->s_line, &data->img[0]->endian);
	return (0);
}

void	pl_init(t_data *data)
{
	data->pl->dex = 0;
	data->pl->dey = 0;
	data->pl->dirx = 0;
	data->pl->diry = 0;
	data->pl->plx = 0;
	data->pl->ply = 0;
	data->pl->rot = 0;
	data->pl->totalrots = 0;
}
