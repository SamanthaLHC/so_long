/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_in_my_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:54:06 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/06 11:09:25 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	itox(int i, size_t line_size)
{
	return (i % line_size);
}

int	itoy(int i, size_t line_size)
{
	return (i / line_size);
}

void	load_img(t_setup *s)
{
	int	x;
	int	y;

	if (s->img_ground != NULL)
		return ;
	s->img_wall = mlx_xpm_file_to_image(s->mlx, "./wall.xpm", &x, &y);
	s->img_ground = mlx_xpm_file_to_image(s->mlx, "./ground.xpm", &x, &y);
	s->img_coll = mlx_xpm_file_to_image(s->mlx, "./coll.xpm", &x, &y);
	s->img_exit = mlx_xpm_file_to_image(s->mlx, "./exit.xpm", &x, &y);
	s->img_face[0] = mlx_xpm_file_to_image(s->mlx, "./face.xpm", &x, &y);
	s->img_face[1] = mlx_xpm_file_to_image(s->mlx, "./face1.xpm", &x, &y);
	s->img_face[2] = mlx_xpm_file_to_image(s->mlx, "./face2.xpm", &x, &y);
	s->img_back[0] = mlx_xpm_file_to_image(s->mlx, "./back1.xpm", &x, &y);
	s->img_back[1] = mlx_xpm_file_to_image(s->mlx, "./back2.xpm", &x, &y);
	s->img_back[2] = mlx_xpm_file_to_image(s->mlx, "./back3.xpm", &x, &y);
	s->img_left[0] = mlx_xpm_file_to_image(s->mlx, "./left1.xpm", &x, &y);
	s->img_left[1] = mlx_xpm_file_to_image(s->mlx, "./left2.xpm", &x, &y);
	s->img_left[2] = mlx_xpm_file_to_image(s->mlx, "./left3.xpm", &x, &y);
	s->img_right[0] = mlx_xpm_file_to_image(s->mlx, "./right1.xpm", &x, &y);
	s->img_right[1] = mlx_xpm_file_to_image(s->mlx, "./right2.xpm", &x, &y);
	s->img_right[2] = mlx_xpm_file_to_image(s->mlx, "./right3.xpm", &x, &y);
	s->img_cake = mlx_xpm_file_to_image(s->mlx, "./cake.xpm", &x, &y);
}

void	put_img_in_win(t_setup *s)
{
	int	i;

	i = 0;
	load_img(s);
	while (s->save_in_tab[i])
	{
		if (s->save_in_tab[i] == '1')
			mlx_put_image_to_window(s->mlx, s->win, s->img_wall,
				itox(i, s->line_size) * 48, itoy(i, s->line_size) * 48);
		else if (s->save_in_tab[i] == '0')
			mlx_put_image_to_window(s->mlx, s->win, s->img_ground,
				itox(i, s->line_size) * 48, itoy(i, s->line_size) * 48);
		else if (s->save_in_tab[i] == 'P')
			anim_char(i, s);
		else if (s->save_in_tab[i] == 'C')
			mlx_put_image_to_window(s->mlx, s->win, s->img_coll,
				itox(i, s->line_size) * 48, itoy(i, s->line_size) * 48);
		else if (s->save_in_tab[i] == 'E')
			mlx_put_image_to_window(s->mlx, s->win, s->img_exit,
				itox(i, s->line_size) * 48, itoy(i, s->line_size) * 48);
		else if (s->save_in_tab[i] == 'F')
			mlx_put_image_to_window(s->mlx, s->win, s->img_cake,
				itox(i, s->line_size) * 48, itoy(i, s->line_size) * 48);
		i++;
	}
}
