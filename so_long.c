/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:09:30 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/01 16:10:09 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_var(t_setup *setup)
{
	setup->img_wall = NULL;
	setup->img_ground = NULL;
	setup->img_coll = NULL;
	setup->img_exit = NULL;
	setup->img_left[0] = NULL;
	setup->img_left[1] = NULL;
	setup->img_left[2] = NULL;
	setup->img_left[3] = NULL;
	setup->img_right[0] = NULL;
	setup->img_right[1] = NULL;
	setup->img_right[2] = NULL;
	setup->img_right[3] = NULL;
	setup->img_back[0] = NULL;
	setup->img_back[1] = NULL;
	setup->img_back[2] = NULL;
	setup->img_back[3] = NULL;
	setup->img_face[0] = NULL;
	setup->img_face[1] = NULL;
	setup->img_face[2] = NULL;
	setup->img_face[3] = NULL;
	setup->img_cake = NULL;
	setup->count_coll = 0;
	setup->count_step = 0;
	setup->idx_anim = 0;
	setup->direction = 115;
}

int	starting(t_setup *setup)
{
	setup->mlx = mlx_init();
	if (!setup->mlx)
		return (-1);
	return (0);
}

void	destroy_everything(t_setup *setup)
{
	mlx_destroy_image(setup->mlx, setup->img_wall);
	mlx_destroy_image(setup->mlx, setup->img_ground);
	mlx_destroy_image(setup->mlx, setup->img_cake);
	mlx_destroy_image(setup->mlx, setup->img_coll);
	mlx_destroy_image(setup->mlx, setup->img_exit);
	mlx_destroy_image(setup->mlx, setup->img_left[0]);
	mlx_destroy_image(setup->mlx, setup->img_left[1]);
	mlx_destroy_image(setup->mlx, setup->img_left[2]);
	mlx_destroy_image(setup->mlx, setup->img_right[0]);
	mlx_destroy_image(setup->mlx, setup->img_right[1]);
	mlx_destroy_image(setup->mlx, setup->img_right[2]);
	mlx_destroy_image(setup->mlx, setup->img_face[0]);
	mlx_destroy_image(setup->mlx, setup->img_face[1]);
	mlx_destroy_image(setup->mlx, setup->img_face[2]);
	mlx_destroy_image(setup->mlx, setup->img_back[0]);
	mlx_destroy_image(setup->mlx, setup->img_back[1]);
	mlx_destroy_image(setup->mlx, setup->img_back[2]);
	mlx_destroy_window(setup->mlx, setup->win);
	mlx_destroy_display(setup->mlx);
}

int	main(int ac, char **av)
{
	t_setup	setup;

	if (ac != 2)
	{
		ft_putstr("choose one map in arg", 2);
		return (-1);
	}
	else
	{
		init_var(&setup);
		starting(&setup);
		count_lines(av[1], &setup);
		if (check_ber(av[1], &setup) == -1)
			return (-1);
		copy_data_from_maps_to_tab(av[1], &setup);
		total_collect(&setup);
		if (ft_error(av[1], &setup) == -1)
			return (-1);
		handle_win(&setup);
		free(setup.save_in_tab);
		free(setup.mlx);
	}
	return (0);
}
