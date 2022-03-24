/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:09:30 by sle-huec          #+#    #+#             */
/*   Updated: 2022/03/25 00:10:00 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int starting(t_setup *setup)
{
	//memset sur la struct pour init
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
//	setup->img_cake = NULL;
	setup->count_coll = 0;
	setup->count_step = 0;
	setup->direction = 115;
	setup->mlx = mlx_init();
	if (!setup->mlx)
		return (-1);
	return (0);
}

int main(int ac, char **av)
{
	t_setup setup;

	if (ac == 1)
	{
		printf("no maps, choose map in arg");
		return (-1);
	}
	else
	{
		starting(&setup);
		count_lines(av[1], &setup);
		copy_data_from_maps_to_tab(av[1], &setup);
		total_collect(&setup);
		handle_win(&setup);
		free(setup.save_in_tab);
		free(setup.mlx);
	}
	return 0;
}