/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <pjurdana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:48:55 by pjurdana          #+#    #+#             */
/*   Updated: 2025/02/28 10:49:16 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_win	new_launch(int width, int height, char *str)
{
	t_win	win_return;

	win_return.mlx_ptr = mlx_init();
	win_return.mlx_win = mlx_new_window(win_return.mlx_ptr, width, height, str);
	win_return.width = width;
	win_return.height = height;
	win_return.counter = 0;
	return (win_return);
}
