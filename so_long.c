/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:09:30 by sle-huec          #+#    #+#             */
/*   Updated: 2022/03/23 23:48:34 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int starting(t_setup *setup)
{
	setup->count_coll = 0;
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
		handle_win(&setup);
		//
		printf("collectibles = %d\n", setup.count_coll);
		//

		free(setup.save_in_tab);
		free(setup.mlx);

	}
	return 0;
}