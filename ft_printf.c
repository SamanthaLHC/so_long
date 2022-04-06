/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:21:44 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/06 11:09:15 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_put_smth(va_list arg, const char *format)
{
	int	i;

	i = 0;
	{	
		if (format[i] == 'c')
			ft_putchar(va_arg(arg, int));
		else if (format[i] == 's')
			ft_putstr(va_arg(arg, char *), 1);
		else if ((format[i] == 'd') || (format[i] == 'i'))
			ft_putnbr(va_arg(arg, int));
		else if (format[i] == '%')
			ft_putchar('%');
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	arg;

	va_start (arg, format);
	i = 0;
	while (format[i])
	{	
		if (format[i] != '%')
			ft_putchar(format[i]);
		if (format[i] == '%')
		{
			ft_put_smth(arg, &format[i + 1]);
			i++;
		}
		i++;
	}
	va_end (arg);
	return (0);
}
