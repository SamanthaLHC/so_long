/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:32:13 by sle-huec          #+#    #+#             */
/*   Updated: 2022/02/19 14:55:04 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stddef.h>

char	*get_next_line(int fd);
char	*ft_substr(char *s, int start, int len);
char	*ft_strcpy(char *dst, char *src);
int		ft_strchr(char *s, int c);
size_t	ft_strlen(char *str);

#endif