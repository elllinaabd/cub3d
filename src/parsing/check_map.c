/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radan <radan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:40:11 by radan        #+#    #+#             */
/*   Updated: 2022/10/23 13:58:04 by radan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	add_item(t_map *map, int x, int y)
{
	t_item	*item;
	t_dlist	*tmp2;

	item = malloc(sizeof(t_item));
	if (!item)
		return (1);
	item->type = map->map[y][x];
	item->px = x;
	item->py = y;
	if (isspawn(map->map[y][x]))
	{
		tmp2 = dlstnew(item);
		if (!tmp2)
			return (1);
		dlstadd_back(&map->spawn, tmp2);
	}
	return (0);
}

int	check(t_map *map, size_t *map_len)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (inmap(map->map[y][x]) && !(x && ismap(map->map[y][x - 1])
				&& map->map[y][x + 1] && ismap(map->map[y][x + 1])
				&& y && map_len[y - 1] >= x + 1 && ismap(map->map[y - 1][x - 1])
				&& ismap(map->map[y - 1][x]) && ismap(map->map[y - 1][x + 1])
				&& map->map[y + 1] && map_len[y + 1] >= x
				&& ismap(map->map[y + 1][x - 1])
				&& ismap(map->map[y + 1][x]) && ismap(map->map[y + 1][x + 1])))
				return (write_error("Error\nMap isnt close\n"));
			if (isspawn(map->map[y][x]))
				if (add_item(map, x, y))
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	cpl_map_len(char **map, size_t	**map_len)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!(ismap(map[y][x]) || map[y][x] == 32 || map[y][x] == '\n'))
				return (write_error("Error\nMap elem error\n"));
			x++;
		}
		(*map_len)[y] = x;
		y++;
	}
	return (0);
}

int	check_map(t_map *map)
{
	size_t	*map_len;

	map_len = malloc(sizeof(size_t) * map->map_len);
	if (!map_len)
		return (write_error("Error\nNeed map\n"));
	if (cpl_map_len(map->map, &map_len))
	{
		free(map_len);
		return (1);
	}
	if (check(map, map_len))
	{
		free(map_len);
		return (1);
	}
	if (!map->spawn)
	{
		free(map_len);
		return (write_error("Error\nNeed spawn\n"));
	}
	free(map_len);
	return (0);
}
