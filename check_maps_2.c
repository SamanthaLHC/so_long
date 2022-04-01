/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:13:18 by sam               #+#    #+#             */
/*   Updated: 2022/04/01 01:49:05 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_wall(t_setup *setup)
{
	size_t i;
	size_t j;
	size_t last_line_start;
	size_t	last_char_idx;

	i = 0;
	j = setup->line_size - 1;
	last_char_idx = ft_strlen(setup->save_in_tab);
	last_line_start = last_char_idx - setup->line_size;
	while(setup->save_in_tab[i])
	{
		while(i <= j && i < setup->line_size)
		{
			if(setup->save_in_tab[i] != '1')
			{
				ft_putstr("error\nInvalid map, missing walls, 1\n", 2);
				return(-1);
			}
			i++;
		}
		while(i < last_line_start)
		{
			j += setup->line_size;
			if (setup->save_in_tab[i] != '1' || setup->save_in_tab[j] != '1')
			{
				ft_putstr("error\nInvalid map, missing walls, 2\n", 2);
				return(-1);
			}
			i += setup->line_size;
		}
		if(setup->save_in_tab[i] != '1')
		{
			ft_printf("%d:%c\n", i, setup->save_in_tab[i]);
			ft_putstr("error\nInvalid map, missing walls, 3\n", 2);
			return(-1);
		}
		i++;
	}
	return(0);
}

int ft_error(char *file, t_setup *setup)
{
	if (check_too_big(setup) == -1)
		return(-1);
	if (check_odd_char(setup) == -1)
		return(-1);
	if (check_rectangle(file, setup) == -1)
		return(-1);
	if (check_wall(setup) == -1)
		return(-1);
	if (check_chars(file, setup) == -1)
		return(-1);
	return(0);
}