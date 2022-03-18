/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:29:51 by sle-huec          #+#    #+#             */
/*   Updated: 2022/03/18 15:33:57 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#define ItoX(i, linesz) (i % linesz)
#define ITOY(i, linesz) (i / linesz)
#define IDX(i, linesz) (x + (linesz * y))

typedef struct s_setup
{
    void *mlx;
    void *win;
    int line_size;
    int nbr_lines;
    char **save_in_tab;
} t_setup;

typedef struct s_img
{

} t_img;

char    *get_next_line(int fd);
char    *ft_substr(char *s, int start, int len);
char    *ft_strcpy(char *dst, char *src);
int ft_strchr(char *s, int c);
size_t  ft_strlesn(char *str);
int count_lines(char *path, t_setup *setup);
char *copy_data_from_maps_to_tab(char *path, t_setup *setup)

#endif

