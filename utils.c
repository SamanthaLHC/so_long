/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:29:33 by sam               #+#    #+#             */
/*   Updated: 2022/03/25 13:48:27 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void total_collect(t_setup *setup)
{
    int i;

    i = 0;
    setup->total_coll = 0;
    while (setup->save_in_tab[i])
    {
        if (setup->save_in_tab[i] == 'C')
        {
            setup->total_coll++;
        }
        i++;
    }
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

char *ft_putstr(char *s)
{
    int ret;
	ret = write(1, s, ft_strlen(s));
    (void)ret;
    return (0);
}

int	ft_putnbr(int n)
{
	unsigned int	num;

	if (n < 0)
	{
		ft_putchar('-');
		num = n * -1;
	}
	else
		num = n;
	if (num > 9)
		ft_putnbr(num / 10);
	ft_putchar(num % 10 + '0');
	return (0);
}