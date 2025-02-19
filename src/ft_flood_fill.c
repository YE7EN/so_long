/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <pjurdana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:10:47 by qumiraud          #+#    #+#             */
/*   Updated: 2025/02/19 12:27:12 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_flood_fill(char **map_tab, int *c, int x, int y)
{
	if (map_tab[y][x] == 'C' || map_tab[y][x] == 'E')
		(*c)--;
	if (map_tab[y][x] != '1' && map_tab[y][x] != 'X')
	{
		map_tab[y][x] = 'X';
		ft_flood_fill(map_tab, c, (x + 1), y);
		ft_flood_fill(map_tab, c, x, (y + 1));
		ft_flood_fill(map_tab, c, (x - 1), y);
		ft_flood_fill(map_tab, c, x, (y - 1));
	}
	if (*c == -1)
		return (0);
	return (8);
}

int	ft_prep_tab(t_map **map_lst, char ***map_tab)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	ft_init_map(map_lst, map_tab);
	ft_clear_maplines(map_lst);
	while ((*map_tab)[i])
	{
		c += ft_count_element_c((*map_tab)[i], c);
		i++;
	}
	return(ft_flood_fill((*map_tab), &c, ft_get_pos_x(*map_tab), ft_get_pos_y(*map_tab)));
}
