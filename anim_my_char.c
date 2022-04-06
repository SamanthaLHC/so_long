/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_my_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:05:51 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/06 11:09:04 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	anim_up(int i, t_setup *setup)
{
	if (setup->img_back[setup->idx_anim] == NULL)
		setup->idx_anim = 0;
	mlx_put_image_to_window(setup->mlx, setup->win,
		setup->img_back[setup->idx_anim],
		itox(i, setup->line_size) * 48, itoy(i, setup->line_size) * 48);
}

void	anim_down(int i, t_setup *setup)
{
	if (setup->img_face[setup->idx_anim] == NULL)
		setup->idx_anim = 0;
	mlx_put_image_to_window(setup->mlx, setup->win,
		setup->img_face[setup->idx_anim],
		itox(i, setup->line_size) * 48, itoy(i, setup->line_size) * 48);
}

void	anim_left(int i, t_setup *setup)
{
	if (setup->img_left[setup->idx_anim] == NULL)
		setup->idx_anim = 0;
	mlx_put_image_to_window(setup->mlx, setup->win,
		setup->img_left[setup->idx_anim],
		itox(i, setup->line_size) * 48, itoy(i, setup->line_size) * 48);
}

void	anim_right(int i, t_setup *setup)
{
	if (setup->img_right[setup->idx_anim] == NULL)
		setup->idx_anim = 0;
	mlx_put_image_to_window(setup->mlx, setup->win,
		setup->img_right[setup->idx_anim],
		itox(i, setup->line_size) * 48, itoy(i, setup->line_size) * 48);
}

void	anim_char(int i, t_setup *setup)
{
	if (setup->direction == 119)
		anim_up(i, setup);
	else if (setup->direction == 97)
		anim_right(i, setup);
	else if (setup->direction == 115)
		anim_down(i, setup);
	else if (setup->direction == 100)
		anim_left(i, setup);
}
