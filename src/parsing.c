/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <pjurdana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:16:53 by pjurdana          #+#    #+#             */
/*   Updated: 2025/03/03 14:46:56 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_map_element(t_map *map_lines)
{
	t_map	*nav;
	int		p;
	int		c;
	int		e;

	p = 0;
	c = 0;
	e = 0;
	nav = map_lines;
	while (nav)
	{
		if (ft_count_element_true(nav->map_line) != 0)
			return (6);
		p += ft_count_element_p(nav->map_line, p);
		c += ft_count_element_c(nav->map_line, c);
		e += ft_count_element_e(nav->map_line, e);
		nav = nav->next;
	}
	if (p != 1)
		return (3);
	else if (c < 1)
		return (4);
	else if (e != 1)
		return (5);
	return (0);
}

int	ft_map_content(t_map **map_lines)
{
	int	map_elem_res;

	map_elem_res = 0;
	map_elem_res = ft_map_element(*map_lines);
	if (map_elem_res != 0)
		return (map_elem_res);
	return (0);
}

void	map_in_struct(int fd, t_map **map_lines)
{
	int		i;
	t_map	*nav;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		return ;
	while (line)
	{
		ft_addline_back(map_lines, ft_newline_map(line));
		line = get_next_line(fd);
		if (!line)
			return ;
	}
	nav = (*map_lines);
	while (nav)
	{
		nav->index_line = i;
		i++;
		nav = nav->next;
	}
	return ;
}

int	ft_map_form(int fd, t_map **map_lines, int i)
{
	t_map	*nav_map_lines;

	map_in_struct(fd, map_lines);
	if (*map_lines == NULL)
	{
		close (fd);
		return (2);
	}
	nav_map_lines = (*map_lines);
	if (fd <= 0)
		ft_exit_fd(fd);
	if (nav_map_lines->len > 22)
	{
		close (fd);
		return (10);
	}
	if (ft_ref_map_form(nav_map_lines, fd) != 0)
		return (2);
	i = ft_ref_2_map_form(nav_map_lines, i);
	if (i > 14)
	{
		close (fd);
		return (10);
	}
	return (0);
}

int	ref_map_file(char *str, int i, int parse_res, t_map **map_lines)
{
	int	fd;

	fd = 0;
	if (str[i - 1] == 'r' && str[i - 2] == 'e'
		&& str[i - 3] == 'b' && str[i - 4] == '.')
	{
		fd = open(str, O_RDONLY);
		if (fd > 0)
		{
			parse_res = ft_map_form(fd, map_lines, 0);
			close (fd);
			if (parse_res == 0)
			{
				parse_res = ft_map_content(map_lines);
				if (parse_res == 0)
					return (0);
				else
					return (parse_res);
			}
			else
				return (parse_res);
		}
	}
	return (1);
}
