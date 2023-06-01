/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:03:21 by myagiz            #+#    #+#             */
/*   Updated: 2023/05/31 22:07:28 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	setup_mlx(t_fractol *frctl)
{
	t_mlx	*mlx;

	frctl->mlx = malloc(sizeof(t_mlx));
	if (frctl->mlx == NULL)
		free_kill_all(frctl);
	mlx = frctl->mlx;
	mlx->ptr = mlx_init();
	if (mlx->ptr == NULL)
		free_kill_all(frctl);
	mlx->win = mlx_new_window(mlx->ptr, SIZE_X, SIZE_Y, "fractol");
	if (mlx->win == NULL)
		free_kill_all(frctl);
	mlx->img.ptr = mlx_new_image(mlx->ptr, SIZE_X, SIZE_Y);
	if (mlx->img.ptr == NULL)
		free_kill_all(frctl);
	mlx->img.addr = mlx_get_data_addr(mlx->img.ptr, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
	if (mlx->img.addr == NULL)
		free_kill_all(frctl);
	mlx_key_hook(mlx->win, key_actions, frctl);
	mlx_mouse_hook(mlx->win, zoom, frctl);
	mlx_hook(mlx->win, 17, 0, free_kill_all, frctl);
	mlx_hook(mlx->win, 6, 0, julia_mouse_motion, frctl);
}
