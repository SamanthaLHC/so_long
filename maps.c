/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 22:21:14 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/10 14:13:56 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *path, t_setup *setup)
{
	int		fd;
	int		ret;
	char	*line;

	ret = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	setup->nbr_lines = 0;
	setup->line_size = ft_strlen(line);
	if (line)
		setup->line_size -= !!(line[ft_strlen(line) - 1] == '\n');
	while (line != NULL)
	{
		setup->nbr_lines += 1;
		if (setup->line_size != (ft_strlen(line)
				- !!(line[ft_strlen(line) - 1] == '\n')))
			ret = -1;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (setup->line_size == 0 || setup->nbr_lines == 0)
		ret = -1;
	return (ret);
}

char	*copy_data_from_maps_to_tab(char *path, t_setup *setup)
{
	char	*line;
	int		i;
	int		j;
	int		fd;

	j = 0;
	fd = open(path, O_RDONLY);
	setup->save_in_tab = malloc(sizeof(*setup->save_in_tab)
			* (setup->line_size * setup->nbr_lines + 1));
	if (!setup->save_in_tab)
		return (NULL);
	setup->save_in_tab[setup->line_size * setup->nbr_lines] = '\0';
	line = get_next_line(fd);
	while (line != NULL)
	{
		line[setup->line_size] = 0;
		i = 0;
		while (line[i])
			setup->save_in_tab[j++] = line[i++];
		free(line);
		line = get_next_line(fd);
	}
	return (setup->save_in_tab);
}
