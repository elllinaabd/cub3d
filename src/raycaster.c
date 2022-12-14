/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radan <radan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:11:18 by radan        #+#    #+#             */
/*   Updated: 2022/10/23 13:41:13 by radan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	is_side(t_data *ptr)
{
	ptr->dda->hit = 1;
	if (!ptr->dda->side)
	{
		if (ptr->dda->raydir_x < 0)
			ptr->dda->side = 1;
		else if (ptr->dda->raydir_x > 0)
			ptr->dda->side = 2;
	}
	else if (ptr->dda->side == 1)
	{
		if (ptr->dda->raydir_y < 0)
			ptr->dda->side = 3;
		else if (ptr->dda->raydir_y > 0)
			ptr->dda->side = 4;
	}
}

void	check_dist_step(t_data *ptr)
{
	if (ptr->dda->sidedist_x < ptr->dda->sidedist_y)
	{
		ptr->dda->sidedist_x += ptr->dda->deltadist_x;
		ptr->dda->map_x += ptr->dda->stepx;
		ptr->dda->side = 0;
	}
	else
	{
		ptr->dda->sidedist_y += ptr->dda->deltadist_y;
		ptr->dda->map_y += ptr->dda->stepy;
		ptr->dda->side = 1;
	}
	if (ptr->map->map[ptr->dda->map_x][ptr->dda->map_y] == '1')
		is_side(ptr);
}

void	check_dist(t_data *ptr)
{
	ptr->dda->hit = 0;
	ptr->dda->side = 0;
	while (ptr->dda->hit == 0)
		check_dist_step(ptr);
	if (ptr->dda->side == 1 || ptr->dda->side == 2 || \
		ptr->dda->side == 13 || ptr->dda->side == 14)
		ptr->dda->walldist = (ptr->dda->map_x - ptr->pl->posx + \
			(1 - ptr->dda->stepx) / 2) / ptr->dda->raydir_x;
	else if (ptr->dda->side == 3 || ptr->dda->side == 4 || \
			ptr->dda->side == 15 || ptr->dda->side == 16)
		ptr->dda->walldist = (ptr->dda->map_y - ptr->pl->posy + \
			(1 - ptr->dda->stepy) / 2) / ptr->dda->raydir_y;
}

void	check_side(t_data *ptr)
{
	if (ptr->dda->raydir_x < 0)
	{
		ptr->dda->stepx = -1;
		ptr->dda->sidedist_x = (ptr->pl->posx - \
			ptr->dda->map_x) * ptr->dda->deltadist_x;
	}
	else
	{
		ptr->dda->stepx = 1;
		ptr->dda->sidedist_x = (ptr->dda->map_x + 1.0 - \
			ptr->pl->posx) * ptr->dda->deltadist_x;
	}
	if (ptr->dda->raydir_y < 0)
	{
		ptr->dda->stepy = -1;
		ptr->dda->sidedist_y = (ptr->pl->posy - \
			ptr->dda->map_y) * ptr->dda->deltadist_y;
	}
	else
	{
		ptr->dda->stepy = 1;
		ptr->dda->sidedist_y = (ptr->dda->map_y + 1.0 - \
			ptr->pl->posy) * ptr->dda->deltadist_y;
	}
}
