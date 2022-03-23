/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:29:51 by sle-huec          #+#    #+#             */
/*   Updated: 2022/03/23 23:48:13 by sam              ###   ########.fr       */
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

#define ITOX(i, line_size) (i % line_size)
#define ITOY(i, line_size) (i / line_size)
#define IDX(i, line_size) (x + (line_size * y))

typedef struct s_setup
{
    void *mlx;
    void *win;
    int line_size;
    int nbr_lines;
    int w_win;
    int h_win;
    char *save_in_tab;
    void    *img_wall;
    void    *img_ground;
    void    *img_char_face1;
    void    *img_coll;
    void    *img_exit;
    int count_coll;
    int total_coll;
} t_setup;


char    *get_next_line(int fd);
char    *ft_substr(char *s, int start, int len);
char    *ft_strcpy(char *dst, char *src);
int ft_strchr(char *s, int c);
size_t  ft_strlesn(char *str);
int count_lines(char *path, t_setup *setup);
char *copy_data_from_maps_to_tab(char *path, t_setup *setup);
void get_size_win(t_setup *setup);
int key_close(int keycode, t_setup *setup);
int mouse_close (t_setup *setup);
void handle_win(t_setup *setup);
int starting(t_setup *setup);
void load_img(t_setup *setup);
void put_img_in_win(t_setup *setup);
int move_char(int keycode, t_setup *setup);
void load_img(t_setup *setup);
void total_collect(t_setup *setup);


#endif

