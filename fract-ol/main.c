/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelis <pmelis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:46:21 by pmelis            #+#    #+#             */
/*   Updated: 2023/11/10 12:30:40 by pmelis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

/*
fractal:		Generates fractals, mandelbrot or julia (with parameters or not)

Parameters:		int argc
				char **argv

return:			int

How it works:	1. If 2 arguments passed (mandel or julia) or 4 (julia)
					2. set fractal.name to argv[1]
					3. If 4 args passed
						4. julia_x = atod(argv[2])
						5. julia_y = atod(argv[3])
					6. Initialize fractol
					7. Hook for keys
					8. Hook for mouse
					9. Hook for (x)
					10. Render fractal
					11. mlx_loop to display window
				12. else (2 args not julia or man) (invalid input)
					13. input_error()
					14. exit();
*/
int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && (!ft_strncmp(argv[1], "mandelbrot\0", 11)
				|| !ft_strncmp(argv[1], "julia\0", 6)))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia\0", 6)))
	{
		fractal.name = argv[1];
		init_fractol(&fractal);
		if (argc == 4)
		{
			fractal.julia_x = atod(argv[2]);
			fractal.julia_y = atod(argv[3]);
		}
		mlx_hook(fractal.win, 2, 1L << 0, key_handler, &fractal);
		mlx_hook(fractal.win, 4, 1L << 2, mouse_handler, &fractal);
		mlx_hook(fractal.win, 17, 1L << 17, close_fractol, &fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx);
	}
	else
	{
		input_error();
		exit(1);
	}
}
