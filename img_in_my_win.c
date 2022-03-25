/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_in_my_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:54:06 by sam               #+#    #+#             */
/*   Updated: 2022/03/25 11:54:27 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_img(t_setup *setup)
{
    int x;
    int y;

    if (setup->img_ground != NULL)
        return;
    setup->img_wall = mlx_xpm_file_to_image(setup->mlx, "./wall.xpm", &x, &y);
    setup->img_ground = mlx_xpm_file_to_image(setup->mlx, "./ground.xpm", &x, &y);
    setup->img_coll = mlx_xpm_file_to_image(setup->mlx, "./coll.xpm", &x, &y);
    setup->img_exit = mlx_xpm_file_to_image(setup->mlx, "./exit.xpm", &x, &y);
	setup->img_face[0] = mlx_xpm_file_to_image(setup->mlx, "./face.xpm", &x, &y);
    setup->img_face[1] = mlx_xpm_file_to_image(setup->mlx, "./face1.xpm", &x, &y);
    setup->img_face[2] = mlx_xpm_file_to_image(setup->mlx, "./face2.xpm", &x, &y);
    setup->img_back[0] = mlx_xpm_file_to_image(setup->mlx, "./back1.xpm", &x, &y);
    setup->img_back[1] = mlx_xpm_file_to_image(setup->mlx, "./back2.xpm", &x, &y);
    setup->img_back[2] = mlx_xpm_file_to_image(setup->mlx, "./back3.xpm", &x, &y);
    setup->img_left[0] = mlx_xpm_file_to_image(setup->mlx, "./left1.xpm", &x, &y);
    setup->img_left[1] = mlx_xpm_file_to_image(setup->mlx, "./left2.xpm", &x, &y);
    setup->img_left[2] = mlx_xpm_file_to_image(setup->mlx, "./left3.xpm", &x, &y);
    setup->img_right[0] = mlx_xpm_file_to_image(setup->mlx, "./right1.xpm", &x, &y);
    setup->img_right[1] = mlx_xpm_file_to_image(setup->mlx, "./right2.xpm", &x, &y);
    setup->img_right[2] = mlx_xpm_file_to_image(setup->mlx, "./right3.xpm", &x, &y);
    setup->img_cake = mlx_xpm_file_to_image(setup->mlx, "./cake.xpm", &x, &y);
}

void put_img_in_win(t_setup *setup)
{
    int i;
    
    i = 0;
    load_img(setup);
    while (setup->save_in_tab[i])
    {
        if (setup->save_in_tab[i] == '1')
        {
            mlx_put_image_to_window(setup->mlx, setup->win, setup->img_wall, 
               ITOX(i, setup->line_size) * 48, ITOY(i, setup->line_size) * 48);
            printf("wall = %c\n", setup->save_in_tab[i]);
        }
        else if (setup->save_in_tab[i] == '0')
        {
            mlx_put_image_to_window(setup->mlx, setup->win, setup->img_ground, 
                ITOX(i, setup->line_size) * 48, ITOY(i, setup->line_size) * 48);
            printf("ground = %c\n", setup->save_in_tab[i]);
        }
        else if (setup->save_in_tab[i] == 'P')
        {
            anim_char(i, setup);
            printf("perso = %c\n", setup->save_in_tab[i]);
        }
        else if (setup->save_in_tab[i] == 'C')
        {
            mlx_put_image_to_window(setup->mlx, setup->win, setup->img_coll, 
                ITOX(i, setup->line_size) * 48, ITOY(i, setup->line_size) * 48);
            printf("coll = %c\n", setup->save_in_tab[i]);
 
        }
        else if (setup->save_in_tab[i] == 'E')
        {
            mlx_put_image_to_window(setup->mlx, setup->win, setup->img_exit, 
                ITOX(i, setup->line_size) * 48, ITOY(i, setup->line_size) * 48);
            printf("exit = %c\n", setup->save_in_tab[i]);
                
        }
        else if (setup->save_in_tab[i] == 'F')
        {
            mlx_put_image_to_window(setup->mlx, setup->win, setup->img_cake, 
                ITOX(i, setup->line_size) * 48, ITOY(i, setup->line_size) * 48);
            printf("foe = %c\n", setup->save_in_tab[i]);
                
        }
        i++;
    }
}