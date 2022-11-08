/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radan <radan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:52:29 by radan        #+#    #+#             */
/*   Updated: 2022/10/26 11:42:45 by radan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	find_max(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}

int	find_mod(int num)
{
	if (0 > num)
		return (-num);
	return (num);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int		*dst;

	dst = (void *)img->p_img + (y * img->s_line + x * \
		(img->bt / 8));
	*(int *)dst = color;
}
