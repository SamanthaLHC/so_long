/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:31:33 by sam               #+#    #+#             */
/*   Updated: 2022/03/18 18:58:13 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int get_size_win(t_setup *setup)
{
    setup->w_win = setup->line_size * 96;
    setup->h_win = setup->nbr_lines * 96;
	setup->win = mlx_new_window(setup->mlx, setup->w_win, setup->h_win,
    "thanks for all the fish, music band");
    return (0);
}

int key_close(int keycode, t_setup *setup)
{
	if (keycode == 65307)
		mlx_loop_end(setup->mlx);
	return(0);
}

int mouse_close (t_setup *setup)
{
	mlx_loop_end(setup->mlx);
	return(0);
}

int handle_win(t_setup *setup)
{    
    get_size_win(setup);
    mlx_hook(setup->win, 2, (1L<<0), &key_close, &setup);	
	mlx_hook(setup->win, 17, 0, &mouse_close, (&setup));
	mlx_loop(setup->mlx);
	mlx_destroy_window(setup->mlx, setup->win);
	mlx_destroy_display(setup->mlx);
    return (0);
}