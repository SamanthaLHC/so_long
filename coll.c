/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coll.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:29:33 by sam               #+#    #+#             */
/*   Updated: 2022/03/24 23:11:13 by sam              ###   ########.fr       */
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
