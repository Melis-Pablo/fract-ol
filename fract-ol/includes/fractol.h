/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelis <pmelis@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:46:36 by pmelis            #+#    #+#             */
/*   Updated: 2023/11/09 13:17:07 by pmelis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h> //malloc free exit
# include <stdio.h> //perror
# include <unistd.h> //close read write
# include "../mlx/mlx.h" //all minilibx functions

# define WIDTH 800
# define HEIGHT 800

# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5
# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124
# define MAIN_PAD_PLUS		24
# define MAIN_PAD_MINUS		27
# define MAIN_PAD_ESC		53

# define RGB_BLACK       0x000000
# define RGB_WHITE       0xFFFFFF
# define RGB_RED         0xFF0000
# define RGB_GREEN       0x00FF00
# define RGB_BLUE        0x0000FF
# define RGB_YELLOW      0xFFFF00
# define RGB_MAGENTA     0xFF00FF
# define RGB_CYAN        0x00FFFF
# define RGB_GRAY        0x808080
# define RGB_LIGHT_GRAY  0xC0C0C0
# define RGB_DARK_GRAY   0x404040

///////////////////////////////
///////-----Structs-----///////
///////////////////////////////
typedef struct s_complex{
	double	r;
	double	i;
}	t_complex;

typedef struct s_img{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal {
	char	*name;
	void	*mlx;
	void	*win;
	t_img	img;
	double	escaped_val;
	int		iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_fractal;

///////////////////////////////
///////---math_utils----///////
///////////////////////////////
double		scale(double unscaled, double new_min,
				double new_max, double old_max);
t_complex	complex_square(t_complex a);
t_complex	complex_sum(t_complex a, t_complex b);

///////////////////////////////
///////----str_utils----///////
///////////////////////////////
void		putstr_fd(char *s, int fd);
void		input_error(void);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
double		atod(char	*str);

///////////////////////////////
///////------init-------///////
///////////////////////////////
void		malloc_error(void);
int			close_fractol(t_fractal *fractal);
void		data_init(t_fractal *fractal);
void		init_fractol(t_fractal *fractal);

///////////////////////////////
///////----rendering----///////
///////////////////////////////
int			fractal_render(t_fractal *fractal);

///////////////////////////////
///////-----events------///////
///////////////////////////////
int			key_handler(int keycode, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);

#endif
