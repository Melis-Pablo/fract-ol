/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelis <pmelis@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:48:25 by pmelis            #+#    #+#             */
/*   Updated: 2023/11/09 12:03:49 by pmelis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
scale:			Scales something to proportion

Parameters:		double unscaled
				double new_min
				double new_max
				double old_max

return:			double (scaled number)

How it works:	(new_max - new_min) * (unscaled_num - old_min) 
				/ (old_max - old_min) + new_min			---> old_min = 0;

*/
double	scale(double unscaled, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled) / (old_max) + new_min);
}

/*
complex_sum:		Performs a sum on a complex number (struct)

Parameters:			t_complex a
					t_complex b

return:				t_complex result

How it works:		real = a.r + b.r
					i =  a.i + b.i
					return (result)
*/
t_complex	complex_sum(t_complex a, t_complex b)
{
	t_complex	result;

	result.r = a.r + b.r;
	result.i = a.i + b.i;
	return (result);
}

/*
complex_square:		Performs a square on a complex number (struct)

Parameters:			t_complex a

return:				t_complex result

How it works:		real = (x^2 - y^2)
					i =  2*x*y
					return (result)
*/
t_complex	complex_square(t_complex a)
{
	t_complex	result;

	result.r = (a.r * a.r) - (a.i * a.i);
	result.i = 2 * a.r * a.i;
	return (result);
}
