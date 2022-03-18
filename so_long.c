/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:09:30 by sle-huec          #+#    #+#             */
/*   Updated: 2022/03/18 12:41:02 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main (int ac, char **av)
{
	t_setup setup;

	if (ac == 1)
	{
		ft_printf("no maps, choose map in arg");
		return (-1);
	}
	else
	setup.nbr_lines = count_lines(av[1], &setup);
	printf("%d\n", setup.nbr_lines);
	
}