/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_my_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:16:25 by sam               #+#    #+#             */
/*   Updated: 2022/03/25 11:41:23 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_up(int *m, t_setup *setup)
{
    setup->idx_anim += 1;
    if (setup->direction != 119)
        setup->idx_anim = 0;
    setup->direction = 119;
    if (setup->save_in_tab[*m - setup->line_size] =='F')
    {
        printf("YOU LOSE !");
        mlx_loop_end(setup->mlx);
    }
    else if (setup->total_coll == setup->count_coll && 
            setup->save_in_tab[*m - setup->line_size] =='E')
    {
            printf("YOU WIN !");
            mlx_loop_end(setup->mlx);
    }
    else if (setup->save_in_tab[*m - setup->line_size] =='0' ||
            setup->save_in_tab[*m - setup->line_size] =='C')
    {
        if (setup->save_in_tab[*m - setup->line_size] =='C')
            setup->count_coll++;
        setup->save_in_tab[*m] = '0';
        setup->save_in_tab[*m - setup->line_size] = 'P';
        put_img_in_win(setup);
    }
}

void move_down(int *m, t_setup *setup)
{
    setup->idx_anim += 1;
    if (setup->direction != 115)
        setup->idx_anim = 0;
    setup->direction = 115;
    if (setup->save_in_tab[*m + setup->line_size] =='F')
    {
        printf("YOU LOSE !");
        mlx_loop_end(setup->mlx);
    }
    else if (setup->total_coll == setup->count_coll && 
            setup->save_in_tab[*m + setup->line_size] =='E')
    {
        printf("YOU WIN !");
        mlx_loop_end(setup->mlx);
    }
    else if (setup->save_in_tab[*m + setup->line_size] =='0' ||
        setup->save_in_tab[*m + setup->line_size] =='C')
    {
        if (setup->save_in_tab[*m + setup->line_size] =='C')
            setup->count_coll++;
        setup->save_in_tab[*m] = '0';
        setup->save_in_tab[*m + setup->line_size] = 'P';
        put_img_in_win(setup);
    }
}

void move_left(int *m, t_setup *setup)
{
    setup->idx_anim += 1;
    if (setup->direction != 100)
        setup->idx_anim = 0;
    setup->direction = 100;
    if (setup->total_coll == setup->count_coll && 
            setup->save_in_tab[*m - 1] =='E')
    {
        printf("YOU WIN !");
        mlx_loop_end(setup->mlx);
    }
    else if (setup->save_in_tab[*m - 1] =='F')
    {
        printf("YOU LOSE !");
        mlx_loop_end(setup->mlx);
    }
    else if (setup->save_in_tab[*m - 1] =='0' ||
        setup->save_in_tab[*m - 1] =='C')
    {
        if (setup->save_in_tab[*m - 1] =='C')
            setup->count_coll++;
        setup->save_in_tab[*m] = '0';
        setup->save_in_tab[*m - 1] = 'P';
        put_img_in_win(setup);
    }    
}

void move_right(int *m, t_setup *setup)
{
    setup->idx_anim += 1;
    if (setup->direction != 97)
        setup->idx_anim = 0;
    setup->direction = 97;
    if (setup->total_coll == setup->count_coll && 
            setup->save_in_tab[*m + 1] =='E')
    {
        printf("YOU WIN !");
        mlx_loop_end(setup->mlx);
    }
    else if (setup->save_in_tab[*m + 1] =='F')
    {
        printf("YOU LOSE !");
        mlx_loop_end(setup->mlx);
    }
    else if (setup->save_in_tab[*m + 1] =='0' ||
        setup->save_in_tab[*m + 1] =='C')
    {
        if (setup->save_in_tab[*m + 1] =='C')
            setup->count_coll++;
        setup->save_in_tab[*m] = '0';
        setup->save_in_tab[*m + 1] = 'P';
        put_img_in_win(setup);
    }
}

int move_char(int keycode, t_setup *setup)
{
    int m;
    
    m = ft_strchr(setup->save_in_tab, 'P');
    if (keycode == 119)
    {
        printf("step's number = %d\n",++setup->count_step);
        move_up(&m, setup);
    }
    else if (keycode == 97)
    {
        printf("step's number = %d\n",++setup->count_step);
        move_left(&m, setup);
    }
    else if (keycode == 115)
    {
        printf("step's number = %d\n",++setup->count_step);
        move_down(&m, setup);
    }
    else if (keycode == 100)
    {
        printf("step's number = %d\n",++setup->count_step);
        move_right(&m, setup);
    }
    return (0);
}