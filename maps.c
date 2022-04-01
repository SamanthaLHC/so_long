/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 22:21:14 by sam               #+#    #+#             */
/*   Updated: 2022/04/01 01:34:00 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int count_lines(char *path, t_setup *setup)
{
	int fd;
	char *line;
	setup->line_size = 0;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	setup->nbr_lines = 0;
	setup->line_size = (ft_strlen(line) - 1);
	while (line != NULL)
	{
		setup->nbr_lines += 1;

		if (setup->line_size != (ft_strlen(line) - 
			!!(line[ft_strlen(line) -1] == '\n')))
		{
			ft_putstr("error\nInvalid map, not rectangle\n", 2);
			free(line);
			return(-1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

char *copy_data_from_maps_to_tab(char *path, t_setup *setup)
{
	char *line;
	int i;
	int j;
	int fd;

	j = 0;
	fd = open(path, O_RDONLY);
	setup->save_in_tab = malloc(sizeof(char) * 
		(setup->line_size * setup->nbr_lines + 1));
	if (!setup->save_in_tab)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		line[setup->line_size] = 0;
		i = 0;
		while (line[i])
			setup->save_in_tab[j++] = line[i++];
		free(line);
		line = get_next_line(fd);
		setup->save_in_tab[j] = '\0';
	}
	return (setup->save_in_tab);
}