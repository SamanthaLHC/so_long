/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:09:30 by sle-huec          #+#    #+#             */
/*   Updated: 2022/03/18 18:49:09 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int starting(t_setup *setup)
{
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
		setup.nbr_lines = count_lines(av[1], &setup);

		//----------
		printf("%d\n", setup.nbr_lines);
		//^^^^^^^^^^^
		
		copy_data_from_maps_to_tab(av[1], &setup);
		
		//----------
		printf("%s\n", *setup.save_in_tab);
		//^^^^^^^^^^^^

		handle_win(&setup);
		free(setup.mlx);

	}
	return 0;
}