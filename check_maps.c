/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:59:11 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/10 21:52:05 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char *file, t_setup *setup)
{
	int	i;

	i = ft_strlen(file);
	while (i > 0)
	{
		if (file[i] == '.')
			break ;
		i--;
	}
	if (ft_strcmp(&file[i], ".ber") == 0)
		return (0);
	ft_putstr("Error\nPlease provide proper .ber file as argument\n", 2);
	mlx_destroy_display(setup->mlx);
	free(setup->mlx);
	return (-1);
}

int	check_chars(char *s, t_setup *setup)
{
	int	count_p;
	int	count_e;

	count_p = 0;
	count_e = 0;
	s = setup->save_in_tab;
	while (*s)
	{
		if (*s == 'P')
			count_p++;
		if (*s == 'E')
			count_e++;
		s++;
	}
	if (setup->total_coll < 1 || count_p != 1 || count_e < 1)
	{
		ft_putstr("Error\nInvalid map, duplicate char P, "
			"or missing element\n", 2);
		mlx_destroy_display(setup->mlx);
		free(setup->mlx);
		free(setup->save_in_tab);
		return (-1);
	}
	return (0);
}

int	check_rectangle(t_setup *setup)
{
	ft_putstr("Error\nInvalid map, not all lines have the same size\n", 2);
	mlx_destroy_display(setup->mlx);
	free(setup->mlx);
	free(setup->save_in_tab);
	return (-1);
}

int	check_odd_char(t_setup *setup)
{
	int	i;

	i = 0;
	while (setup->save_in_tab[i])
	{
		if (setup->save_in_tab[i] != '0' && setup->save_in_tab[i] != '1'
			&&setup->save_in_tab[i] != 'P' && setup->save_in_tab[i] != 'E'
			&& setup->save_in_tab[i] != 'C' && setup->save_in_tab[i] != 'F')
		{
			ft_putstr("Error\nInvalid char in map\n", 2);
			mlx_destroy_display(setup->mlx);
			free(setup->save_in_tab);
			free(setup->mlx);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	check_too_big(t_setup *setup)
{
	if (setup->line_size > 40)
	{
		ft_putstr("Error\nInvalid size\n", 2);
		mlx_destroy_display(setup->mlx);
		free(setup->save_in_tab);
		free(setup->mlx);
		return (-1);
	}
	return (0);
}
