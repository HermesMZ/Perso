/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:07:09 by mzimeris          #+#    #+#             */
/*   Updated: 2025/07/09 17:51:12 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// #define MLX_ERROR       1
// #define WINDOW_WIDTH    400
// #define WINDOW_HEIGHT   400

// int	handle_input(int keysym, t_mlx_data *data)
// {
// 	if (keysym == XK_Escape)
// 	{
// 		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 		mlx_destroy_display(data->mlx_ptr);
// 		free(data->mlx_ptr);
// 		exit(1);
// 	}
// 	return (0);
// }


// int	main(void)
// {
// 	t_mlx_data	data;

// 	data.mlx_ptr = mlx_init();
// 	if (data.mlx_ptr == NULL)
// 		return (MLX_ERROR);
// 	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
// 			"My first window!");
// 	if (data.win_ptr == NULL)
// 	{
// 		mlx_destroy_display(data.mlx_ptr);
// 		free(data.mlx_ptr);
// 		return (MLX_ERROR);
// 	}
// 	mlx_key_hook(data.win_ptr, handle_input, &data);
// 	mlx_loop(data.mlx_ptr);
// }
t_mlx_data	*init_mlx_data(void)
{
	t_mlx_data	*data;
	int			size_x;
	int			size_y;

	size_x = 500;
	size_y = 500;
	data = malloc(sizeof(t_mlx_data));
	if (!data)
		return (NULL);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (NULL);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			size_x, size_y, "MY WORLD");
	if (!data->win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		return (NULL);
	}
	return (data);
}

int	main(void)
{
	t_mlx_data	*data;

	data = init_mlx_data();
	mlx_key_hook(data->win_ptr, handle_input, &data);
	mlx_loop(data->mlx_ptr);
}
