/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <pjurdana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:18:26 by pjurdana          #+#    #+#             */
/*   Updated: 2025/03/03 13:18:27 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_count_element_true(char *line)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (line [i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P'
			&& line[i] != 'E' && line[i] != 'C' && line[i] != '\n')
			x++;
		i++;
	}
	if (x != 0)
		return (x);
	return (0);
}

int	ft_count_element_p(char *line, int p)
{
	int	i;

	i = 0;
	p = 0;
	while (line[i])
	{
		if (line[i] == 'P')
		{
			p++;
		}
		i++;
	}
	return (p);
}

int	ft_count_element_c(char *line, int c)
{
	int	i;

	i = 0;
	c = 0;
	while (line[i])
	{
		if (line[i] == 'C')
		{
			c++;
		}
		i++;
	}
	return (c);
}

int	ft_count_element_e(char *line, int e)
{
	int	i;

	i = 0;
	e = 0;
	while (line[i])
	{
		if (line[i] == 'E')
		{
			e++;
		}
		i++;
	}
	return (e);
}
