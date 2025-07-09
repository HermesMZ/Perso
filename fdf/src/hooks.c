/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:59:59 by mzimeris          #+#    #+#             */
/*   Updated: 2025/07/09 17:48:29 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	end_display(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
	exit(1);
}

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
		end_display(data);
	return (0);
}
