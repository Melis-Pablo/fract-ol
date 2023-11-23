/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelis <pmelis@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:09:22 by pmelis            #+#    #+#             */
/*   Updated: 2023/11/09 13:13:45 by pmelis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
malloc_error:	prints error message using perror() and exits after malloc error

Parameters:		void

return:			void

How it works:	1. perror(message)
				2. exit()
*/
void	malloc_error(void)
{
	perror("Memory Allocation Error");
	exit(1);
}

/*
close_fractol:	Exits program cleanly

Parameters:		t_fractal *fractal

return:			int

How it works:	1. Destroys image created
				2. Destroys window created
				3. Exits()
*/
int	close_fractol(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx, fractal->win);
	exit (0);
}

/*
data_init:		initializes necessary values

Parameters:		t_fractal *fractal

return:			void

How it works:	1. escaped_val (iteration after it is not considered in set)
				2. iterations (iterations to render)
				3. shift_x (for arrow movement)
				4. shift_y (for arrow movement)
				5. zoom (for mouse wheel)
				6. julia_x (random to show something)
				7. julia_y (random to show something)
*/
void	data_init(t_fractal *fractal)
{
	fractal->escaped_val = 4;
	fractal->iterations = 200;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->julia_x = -0.8;
	fractal->julia_y = 0.156;
}

/*
init_fractol:	Initializes fractol &data

Parameters:		t_fractal *fractal

return:			void

How it works:	1. Initialize mlx connection
				2. check for error
					3. malloc error
				4. initialize mlx window
				5. check for error
					6. destroy win & connection & malloc error
				7. Initialize img
				8. check for error
					9. destroy win && image && connection && malloc error
				10. set pixel ptr
				11. data_init()
*/
void	init_fractol(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
		malloc_error();
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->name);
	if (fractal->win == NULL)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		free(fractal->mlx);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		mlx_destroy_image(fractal->mlx, fractal->img.img_ptr);
		free(fractal->mlx);
		malloc_error();
	}
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len,
			&fractal->img.endian);
	data_init(fractal);
}
