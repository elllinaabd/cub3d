/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radan <radan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:26:13 by radan        #+#    #+#             */
/*   Updated: 2022/10/23 14:14:34 by radan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

int	all_face(t_file *file)
{
	if (!file->f1 || !file->f2 || !file->f3
		|| !file->f4 || !file->f5 || !file->f6)
	{
		ft_free(file->no, file->so, file->we, file->ea);
		ft_free(file->c, file->f, file, 0);
		return (1);
	}
	return (0);
}

int	parse_map(t_map *map, t_file *file, char **argv)
{
	char	**tab;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit (write_error("Error\nOpen failed\n"));
	if (get_file(fd, &tab))
	{
		ft_free(file->no, file->so, file->we, file->ea);
		return (ft_free(file->c, file->f, file, 0));
	}
	close(fd);
	if (map_elem(file, tab))
		return (free_tab(tab, 1));
	if (all_face(file))
		return (free_tab(tab, 1));
	if (take_map(file, map, tab))
		return (free_tab(tab, 1));
	if (check_map(map))
	{
		ft_free(file->no, file->so, file->we, file->ea);
		ft_free(file->c, file->f, file, 0);
		return (free_tab(tab, 1));
	}
	return (free_tab(tab, 0));
}

int	ext_cub(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (i && str[i] != '.')
		i--;
	if (!i || ft_strncmp(".cub", &str[i], 4))
		exit (write_error("Error\nBad extension\n"));
	return (0);
}

int	convert_file(t_data *data, t_map *map, t_file *file)
{
	init_texture(data, 1, file->no);
	init_texture(data, 2, file->so);
	init_texture(data, 3, file->we);
	init_texture(data, 4, file->ea);
	ft_free(file->no, file->so, file->we, file->ea);
	init_texture(data, 5, "./res/door1.xpm");
	init_texture(data, 6, "./res/frame_0.xpm");
	init_texture(data, 7, "./res/frame_1.xpm");
	init_texture(data, 8, "./res/frame_2.xpm");
	init_texture(data, 9, "./res/frame_3.xpm");
	init_texture(data, 10, "./res/frame_4.xpm");
	init_texture(data, 11, "./res/frame_5.xpm");
	init_texture(data, 12, "./res/frame_6.xpm");
	init_texture(data, 13, "./res/CustomDoor.xpm");
	init_texture(data, 14, "./res/CustomDoor.xpm");
	init_texture(data, 15, "./res/CustomDoor.xpm");
	init_texture(data, 16, "./res/CustomDoor.xpm");
	if (conv_color(&map->f, file->f) || conv_color(&map->c, file->c))
		exit (write_error("Error\nColor error\n"));
	ft_free(file->c, file->f, file, 0);
	return (0);
}

int	parsing(t_data *data, t_map *map, char **argv)
{
	t_file	*file;

	file = malloc(sizeof(t_file));
	if (!file)
		return (1);
	if (ext_cub(argv[1]))
		return (ft_free(file, 0, 0, 0));
	struct_init(file, map);
	if (parse_map(map, file, argv))
		return (1);
	if (convert_file(data, map, file))
		return (1);
	return (0);
}
