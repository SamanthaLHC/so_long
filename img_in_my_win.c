/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_in_my_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:54:06 by sam               #+#    #+#             */
/*   Updated: 2022/03/18 23:15:30 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_img(t_setup *setup, t_img *img)
{
    int x;
    int y;
    
	img->img_wall = mlx_xpm_file_to_image(setup->mlx, "./wall.xpm", &x, &y);
    img->img_ground = mlx_xpm_file_to_image(setup->mlx, "./ground.xpm", &x, &y);
	img->img_char_face1 = mlx_xpm_file_to_image(setup->mlx, "./wall.xpm", &x, &y);
}

void put_img_in_win(t_setup *setup, t_img *img)
{
    int i;
    
    i = 0;
    load_img(setup, img);
    while (setup->save_in_tab[i])
    {
        if (setup->save_in_tab[i] == '1')
            mlx_put_image_to_window(setup->mlx, setup->win, img->img_wall, 
                ITOX(i, setup->line_size), ITOY(i, setup->line_size));
        else if (setup->save_in_tab[i] == '0')
            mlx_put_image_to_window(setup->mlx, setup->win, img->img_ground, 
                ITOX(i, setup->line_size), ITOY(i, setup->line_size));
        else if (setup->save_in_tab[i] == 'P')
            mlx_put_image_to_window(setup->mlx, setup->win, img->img_char_face1, 
                ITOX(i, setup->line_size), ITOY(i, setup->line_size));
        i++;
    }
}