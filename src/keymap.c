/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:01:54 by quentin           #+#    #+#             */
/*   Updated: 2025/02/24 16:04:09 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	cross_click(void *params)
{
	void	**params_tab = (void **)params;

	mlx_destroy_image(params_tab[0], params_tab[2]);
	mlx_destroy_window(params_tab[0], params_tab[1]);
	mlx_destroy_display(params_tab[0]);
	mlx_loop_end(params_tab[0]);
	free (params_tab[0]);
	exit (EXIT_SUCCESS);
	return (0);
}

int esc_key_press(void *params)
{
	void    **params_tab = (void **)params;

//	params[0] = {mlx};
//	params[1] = {mlx_win};
//	params[2] = {img};
	mlx_destroy_image(params_tab[0], params_tab[2]);
	mlx_destroy_window(params_tab[0], params_tab[1]);
	mlx_destroy_display(params_tab[0]);
	mlx_loop_end(params_tab[0]);
	free (params_tab[0]);
	exit (EXIT_SUCCESS);
	return (0);
}

int	check_pos_player(t_image img)
{
	int	x;
	int	y;

	x = ft_get_pos_x(img.map);
	y = ft_get_pos_y(img.map);
	if (img.map[y][x + 1] != '1')// && img.map[y][x + 1] != 'E')
		return (1);
	if (img.map[y][x - 1] != '1' && img.map[y][x - 1] != 'E')
		return (1);
	if (img.map[y + 1][x] != '1' && img.map[y + 1][x] != 'E')
		return (1);
	if (img.map[y - 1][x] != '1' && img.map[y - 1][x] != 'E')
		return (1);
	return (0);
}

int	ft_count_element_collec(t_image img)
{
	int	i;
	int	j;
	int c;
	char	**map = NULL;

	map = img.map;
	i = 0;
	j = 0;
	c = 0;
	
	printf("\n\n\n map : %d\n\n\n", (*map)[i]);

	// printf ("%s", img.map);
	i = 0;

	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				c++;
			}
			j++;
		}
		i++;
		printf("\nnah%d\n", c);
	}
	return (c);
}



int	key_press(int keycode, t_image *params)
{
	t_image	*params_tab = params;


	int	c = 0;

	c = ft_count_element_collec(*params_tab);
	printf("\nui%d\n", c);




	if (keycode == KEY_ESCAPE) // ESC
		exit_so_long(&params_tab->win);
	if (keycode == KEY_D || keycode == XK_Right)
	{
		if (check_pos_player(*params_tab) != 1)
			return (0);
		move_to_right(*params_tab);
		ft_put_img_on_map(params_tab);
	}
	else if (keycode == KEY_W || keycode == XK_Up)
	{
		if (check_pos_player(*params_tab) != 1)
			return (0);
		move_up(*params_tab);
		ft_put_img_on_map(params_tab);
	}
	else if (keycode == KEY_A || keycode == XK_Left)
	{
		if (check_pos_player(*params_tab) != 1)
			return (0);
		move_to_left(*params_tab);
		ft_put_img_on_map(params_tab);
	}
	else if (keycode == KEY_S || keycode == XK_Down)
	{
		if (check_pos_player(*params_tab) != 1)
			return (0);
		move_down(*params_tab);
		ft_put_img_on_map(params_tab);
	}
	else
		return (0);
	return (0);
}







// int esc_key_press(int keycode, void *params)
// {
//     void    **params_tab = (void **)params;
//     //params[0]={mlx};
//     //params[1]={mlx_win};
//     //params[2]={img};
//     if (keycode == 65307)
//     {
//         mlx_destroy_image( params_tab[0], params_tab[2]);
//         mlx_destroy_window(params_tab[0], params_tab[1]);
//         mlx_destroy_display(params_tab[0]); // gere quasi tout les free
//         mlx_loop_end(params_tab[0]); 
//         free(params_tab[0]);
//         exit (EXIT_SUCCESS);
//     }
//     return (0);
// }


