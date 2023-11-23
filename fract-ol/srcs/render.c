/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelis <pmelis@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:40:03 by pmelis            #+#    #+#             */
/*   Updated: 2023/11/09 13:38:11 by pmelis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
my_pixel_put:	puts pixel of int color to the correct address

Parameters:		int x
				int y
				t_img *img
				int color

return:			void

How it works:	1. Set offset to correct amount using line_len and bpp
				2. Set address to color
*/
static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

/*
mandel_julia:	sets c values depending on fractal chosen

Parameters:		t_complex *z
				t_complex *c
				t_fractal *fractal

return:			void

How it works:	1. If julia, set c values to julia
				2. if mandelbrot, set c values to initial z values
*/
static void	mandel_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->r = fractal->julia_x;
		c->i = fractal->julia_y;
	}
	else
	{
		c->r = z->r;
		c->i = z->i;
	}
}

/*
pixel_filler:	colors pixel

Parameters:		int x
				int y
				t_fractal *fractal

return:			void

How it works:	1. set z values scaling for window (accounting for zoom & shift)
				2. set c values mandel_julia()
				3. Iterate
					4. using mandel formula & escaped_val set color
					5. color pixel
				6. i++ 
				7. fill in
*/
static void	pixel_filler(int x,	int y,	t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.r = (scale(x, -2, 2, WIDTH - 1) * fractal->zoom) + fractal->shift_x;
	z.i = (scale(y, 2, -2, HEIGHT - 1) * fractal->zoom) + fractal->shift_y;
	mandel_julia(&z, &c, fractal);
	while (i < fractal->iterations)
	{
		z = complex_sum(complex_square(z), c);
		if ((z.r * z.r) + (z.i * z.i) > fractal->escaped_val)
		{
			color = scale(i, RGB_BLACK, RGB_WHITE, fractal->iterations);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, RGB_WHITE);
}

/*
fractal_render:		renders fractal on window

Parameters:			t_fractal *fractal

return:				int

How it works:		1. Iterate through every pixel and fill it
					2. mlx_put_image_to_window()
					3. return 0
*/
int	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pixel_filler(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win,
		fractal->img.img_ptr, 0, 0);
	return (0);
}
