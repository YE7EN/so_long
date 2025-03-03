/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <pjurdana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:17:01 by pjurdana          #+#    #+#             */
/*   Updated: 2025/03/03 14:48:43 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_map_file_name(char *str, t_map **map_lines)
{
	int	i;
	int	parse_res;

	i = 0;
	parse_res = 0;
	while (str[i] != '\0')
		i++;
	if (i == 4)
		return (1);
	return (ref_map_file(str, i, parse_res, map_lines));
}

void	ft_exit_fd(int fd)
{
	close (fd);
	exit(EXIT_FAILURE);
}

int	ft_ref_map_form(t_map *nav_map_lines, int fd)
{
	while (nav_map_lines->next)
	{
		if (nav_map_lines->len != nav_map_lines->next->len)
		{
			close (fd);
			return (2);
		}
		nav_map_lines = nav_map_lines->next;
	}
	return (0);
}

int	ft_ref_2_map_form(t_map *nav_map_lines, int i)
{
	while (nav_map_lines->next)
	{
		i++;
		nav_map_lines = nav_map_lines->next;
	}
	return (i);
}
