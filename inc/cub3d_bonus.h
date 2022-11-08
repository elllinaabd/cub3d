/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radan <radan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:14:10 by radan            #+#    #+#             */
/*   Updated: 2022/10/23 14:13:23 by radan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "cub3d.h"

int		mousing(t_data *data);
int		isdoor(char c);
int		isitem(char c);
void	draw_bg(t_data *data);
void	minimap(t_data *data);
void	put_sprite(t_data *data, int y);

#endif