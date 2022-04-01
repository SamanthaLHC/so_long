/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:29:51 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/01 14:56:51 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_setup
{
	void	*mlx;
	void	*win;
	size_t	line_size;
	int		nbr_lines;
	int		w_win;
	int		h_win;
	char	*save_in_tab;
	void	*img_wall;
	void	*img_cake;
	void	*img_left[4];
	void	*img_right[4];
	void	*img_face[4];
	void	*img_back[4];
	int		idx_anim;
	void	*img_ground;
	void	*img_coll;
	void	*img_exit;
	int		count_coll;
	int		total_coll;
	int		count_step;
	int		direction;
}	t_setup;

char	*get_next_line(int fd);
char	*ft_substr(char *s, int start, int len);
char	*ft_strcpy(char *dst, char *src);
int		ft_strchr(char *s, int c);
size_t	ft_strlesn(char *str);
int		count_lines(char *path, t_setup *setup);
char	*copy_data_from_maps_to_tab(char *path, t_setup *setup);
void	get_size_win(t_setup *setup);
int		key_close(int keycode, t_setup *setup);
int		mouse_close(t_setup *setup);
void	handle_win(t_setup *setup);
int		starting(t_setup *setup);
void	load_img(t_setup *setup);
void	put_img_in_win(t_setup *setup);
int		move_char(int keycode, t_setup *setup);
void	load_img(t_setup *setup);
void	total_collect(t_setup *setup);
void	anim_up(int i, t_setup *setup);
void	anim_down(int i, t_setup *setup);
void	anim_left(int i, t_setup *setup);
void	anim_right(int i, t_setup *setup);
void	anim_char(int i, t_setup *setup);
int		ft_putnbr(int n);
char	*ft_putstr(char *s, int fd);
int		ft_putchar(char c);
int		ft_put_smth(va_list arg, const char *format);
int		ft_printf(const char *format, ...);
void	destroy_everything(t_setup *setup);
int		ft_strcmp(char *s1, char *s2);
int		ft_error(char *file, t_setup *setup);
int		check_wall(t_setup *setup);
int		check_ber(char *file, t_setup *setup);
int		check_too_big(t_setup *setup);
int		check_chars(char *s, t_setup *setup);
int		check_rectangle(char *file, t_setup *setup);
int		check_odd_char(t_setup *setup);
int		itox(int i, size_t line_size);
int		itoy(int i, size_t line_size);

#endif
