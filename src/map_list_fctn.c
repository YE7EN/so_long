/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_list_fctn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <pjurdana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:17:43 by pjurdana          #+#    #+#             */
/*   Updated: 2025/03/03 13:17:45 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*ft_newline_map(char *str)
{
	t_map	*new_mapline;

	new_mapline = NULL;
	new_mapline = malloc(sizeof(t_map));
	if (!new_mapline)
		return (NULL);
	new_mapline->map_line = str;
	new_mapline->len = ft_strchrlen(str);
	new_mapline->index_line = 0;
	new_mapline->previous = NULL;
	new_mapline->next = NULL;
	return (new_mapline);
}

int	ft_lst_map_size(t_map *lst_map)
{
	int	i;

	i = 0;
	while (lst_map)
	{
		lst_map = lst_map->next;
		i++;
	}
	return (i);
}

void	ft_addline_back(t_map **line_map, t_map *new_line)
{
	t_map	*nav_linemap;

	if (!*line_map)
	{
		*line_map = new_line;
		return ;
	}
	nav_linemap = *line_map;
	while (nav_linemap->next)
		nav_linemap = nav_linemap->next;
	nav_linemap->next = new_line;
}

void	ft_clear_maplines(t_map **line_map)
{
	t_map	*nav_linemap;

	nav_linemap = NULL;
	if (!line_map)
		return ;
	while (*line_map)
	{
		nav_linemap = *line_map;
		free ((*line_map)->map_line);
		*line_map = (*line_map)->next;
		free(nav_linemap);
	}
	line_map = NULL;
}
