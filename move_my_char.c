/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_my_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:16:25 by sam               #+#    #+#             */
/*   Updated: 2022/03/23 23:35:33 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_up(int *m, t_setup *setup)
{
    if (setup->save_in_tab[*m - setup->line_size] =='0' ||
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
    if (setup->save_in_tab[*m + setup->line_size] =='0' ||
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
    if (setup->save_in_tab[*m - 1] =='0' ||
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
    if (setup->save_in_tab[*m + 1] =='0' ||
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
        move_up(&m, setup);
    else if (keycode == 97)
        move_left(&m, setup);
    else if (keycode == 115)
        move_down(&m, setup);
    else if (keycode == 100)
        move_right(&m, setup);

    return (0);
}