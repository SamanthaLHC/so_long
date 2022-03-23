/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_in_my_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:54:06 by sam               #+#    #+#             */
/*   Updated: 2022/03/23 10:34:38 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_img(t_setup *setup)
{
    int x;
    int y;
    
	setup->img_wall = mlx_xpm_file_to_image(setup->mlx, "./wall.xpm", &x, &y);
    setup->img_ground = mlx_xpm_file_to_image(setup->mlx, "./ground.xpm", &x, &y);
	setup->img_char_face1 = mlx_xpm_file_to_image(setup->mlx, "./face.xpm", &x, &y);
    setup->img_coll = mlx_xpm_file_to_image(setup->mlx, "./coll.xpm", &x, &y);
    setup->img_exit = mlx_xpm_file_to_image(setup->mlx, "./exit.xpm", &x, &y);
}

void put_img_in_win(t_setup *setup)
{
    int i;
    
    i = 0;
    load_img(setup);
    while (setup->save_in_tab[i])
    {
        printf("%c: %i, %i\n", setup->save_in_tab[i],  ITOX(i, setup->line_size), ITOY(i, setup->line_size));
        if (setup->save_in_tab[i] == '1')
            mlx_put_image_to_window(setup->mlx, setup->win, setup->img_wall, 
                ITOX(i, setup->line_size) * 48, ITOY(i, setup->line_size) * 48);
        else if (setup->save_in_tab[i] == '0')
            mlx_put_image_to_window(setup->mlx, setup->win, setup->img_ground, 
                ITOX(i, setup->line_size) * 48, ITOY(i, setup->line_size) * 48);
        else if (setup->save_in_tab[i] == 'P')
            mlx_put_image_to_window(setup->mlx, setup->win, setup->img_char_face1, 
                ITOX(i, setup->line_size) * 48, ITOY(i, setup->line_size) * 48);
        else if (setup->save_in_tab[i] == 'C')
            mlx_put_image_to_window(setup->mlx, setup->win, setup->img_coll, 
                ITOX(i, setup->line_size) * 48, ITOY(i, setup->line_size) * 48);  
        else if (setup->save_in_tab[i] == 'E')
            mlx_put_image_to_window(setup->mlx, setup->win, setup->img_exit, 
                ITOX(i, setup->line_size) * 48, ITOY(i, setup->line_size) * 48);       
        i++;
    }
}