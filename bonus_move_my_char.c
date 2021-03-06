/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_move_my_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:16:25 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/13 12:19:45 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(int *m, t_setup *setup)
{
	setup->idx_anim += 1;
	if (setup->direction != 119)
		setup->idx_anim = 0;
	setup->direction = 119;
	if (setup->save_in_tab[*m - setup->line_size] == 'F')
	{
		ft_putstr("YOU LOSE !", 1);
		mlx_loop_end(setup->mlx);
	}
	else if (setup->total_coll == setup->count_coll
		&& setup->save_in_tab[*m - setup->line_size] == 'E')
	{
		ft_putstr("YOU WIN !", 1);
		mlx_loop_end(setup->mlx);
	}
	else if (setup->save_in_tab[*m - setup->line_size] == '0'
		|| setup->save_in_tab[*m - setup->line_size] == 'C')
	{
		if (setup->save_in_tab[*m - setup->line_size] == 'C')
			setup->count_coll++;
		setup->save_in_tab[*m] = '0';
		setup->save_in_tab[*m - setup->line_size] = 'P';
		put_img_in_win(setup);
	}
}

void	move_down(int *m, t_setup *setup)
{
	setup->idx_anim += 1;
	if (setup->direction != 115)
		setup->idx_anim = 0;
	setup->direction = 115;
	if (setup->save_in_tab[*m + setup->line_size] == 'F')
	{
		ft_putstr("YOU LOSE !", 1);
		mlx_loop_end(setup->mlx);
	}
	else if (setup->total_coll == setup->count_coll
		&& setup->save_in_tab[*m + setup->line_size] == 'E')
	{
		ft_putstr("YOU WIN !", 1);
		mlx_loop_end(setup->mlx);
	}
	else if (setup->save_in_tab[*m + setup->line_size] == '0'
		|| setup->save_in_tab[*m + setup->line_size] == 'C')
	{
		if (setup->save_in_tab[*m + setup->line_size] == 'C')
			setup->count_coll++;
		setup->save_in_tab[*m] = '0';
		setup->save_in_tab[*m + setup->line_size] = 'P';
		put_img_in_win(setup);
	}
}

void	move_left(int *m, t_setup *setup)
{
	setup->idx_anim += 1;
	if (setup->direction != 100)
		setup->idx_anim = 0;
	setup->direction = 100;
	if (setup->total_coll == setup->count_coll
		&& setup->save_in_tab[*m - 1] == 'E')
	{
		ft_putstr("YOU WIN !", 1);
		mlx_loop_end(setup->mlx);
	}
	else if (setup->save_in_tab[*m - 1] == 'F')
	{
		ft_putstr("YOU LOSE !", 1);
		mlx_loop_end(setup->mlx);
	}
	else if (setup->save_in_tab[*m - 1] == '0'
		|| setup->save_in_tab[*m - 1] == 'C')
	{
		if (setup->save_in_tab[*m - 1] == 'C')
			setup->count_coll++;
		setup->save_in_tab[*m] = '0';
		setup->save_in_tab[*m - 1] = 'P';
		put_img_in_win(setup);
	}
}

void	move_right(int *m, t_setup *setup)
{
	setup->idx_anim += 1;
	if (setup->direction != 97)
		setup->idx_anim = 0;
	setup->direction = 97;
	if (setup->total_coll == setup->count_coll
		&& setup->save_in_tab[*m + 1] == 'E')
	{
		ft_putstr("YOU WIN !", 1);
		mlx_loop_end(setup->mlx);
	}
	else if (setup->save_in_tab[*m + 1] == 'F')
	{
		ft_putstr("YOU LOSE !", 1);
		mlx_loop_end(setup->mlx);
	}
	else if (setup->save_in_tab[*m + 1] == '0'
		|| setup->save_in_tab[*m + 1] == 'C')
	{
		if (setup->save_in_tab[*m + 1] == 'C')
			setup->count_coll++;
		setup->save_in_tab[*m] = '0';
		setup->save_in_tab[*m + 1] = 'P';
		put_img_in_win(setup);
	}
}

int	move_char(int keycode, t_setup *setup)
{
	int	m;
	int	m2;

	m = ft_strchr(setup->save_in_tab, 'P');
	if (keycode == 119)
		move_up(&m, setup);
	else if (keycode == 97)
		move_left(&m, setup);
	else if (keycode == 115)
		move_down(&m, setup);
	else if (keycode == 100)
		move_right(&m, setup);
	m2 = ft_strchr(setup->save_in_tab, 'P');
	if (m2 != m)
		ft_printf("step's number = %d\n", ++setup->count_step);
	return (0);
}
