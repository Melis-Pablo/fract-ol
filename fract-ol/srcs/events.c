/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelis <pmelis@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:36:15 by pmelis            #+#    #+#             */
/*   Updated: 2023/11/09 12:38:03 by pmelis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
key_handler:	choses an action depending on the key pressed.

Parameters:		int keycode
				t_fractal *fractal

return:			int

How it works:	1. If esc
					2. Close program
				3. If arrow up
					4. shift_y increase
				5. If arrow down
					6.shift_y decrease
				7. If arrow left
					8. shift_x decrease
				9. If arrow right
					10. shift_x increase
				11. If +
					12. increase iterations
				13. If -
					14. decrease iterations
				15. fractal_render to refresh
*/
int	key_handler(int keycode, t_fractal *fractal)
{
	if (keycode == MAIN_PAD_ESC)
		close_fractol(fractal);
	else if (keycode == ARROW_UP)
		fractal->shift_y += (0.1 * fractal->zoom);
	else if (keycode == ARROW_DOWN)
		fractal->shift_y -= (0.1 * fractal->zoom);
	else if (keycode == ARROW_LEFT)
		fractal->shift_x -= (0.1 * fractal->zoom);
	else if (keycode == ARROW_RIGHT)
		fractal->shift_x += (0.1 * fractal->zoom);
	else if (keycode == MAIN_PAD_PLUS)
		fractal->iterations += 10;
	else if (keycode == MAIN_PAD_MINUS)
		fractal->iterations -= 10;
	fractal_render(fractal);
	return (0);
}

/*
mouse_handler:	Choses what to do on mouse events

Parameters:		int button
				int x
				int y
				t_fractal *fractal

return:			int

How it works:	1. If scroll up
					2. zoom out
				3. If scroll down
					4. zoom in
				5. fractal_render to refresh
				6. random if to get rid of unused variables
*/
int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == MOUSE_SCROLL_DOWN)
		fractal->zoom *= 0.9;
	else if (button == MOUSE_SCROLL_UP)
		fractal->zoom *= 1.1;
	fractal_render(fractal);
	if (x > 500 || y > 500)
		return (1);
	return (0);
}
