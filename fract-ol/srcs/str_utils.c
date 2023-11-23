/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelis <pmelis@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:52:16 by pmelis            #+#    #+#             */
/*   Updated: 2023/11/09 11:43:11 by pmelis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
putstr_fd:		Prints str into file descriptor.

Parameters:		char *s;
				int	fd;

return:			void

How it works:	1. checks for invalid input
					2. return
				3. if s still going
					4. write s into fd
					5. putstr_fd(s + 1) Recursively prints until end
*/
void	putstr_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	if (*s)
	{
		write(fd, s, 1);
		putstr_fd(s + 1, fd);
	}
}

/*
input_error:	Prints correct input options.

Parameters:		void

return:			void

How it works:	Uses putstr_fd to print the options to stderr.
*/
void	input_error(void)
{
	putstr_fd("Please choose between:\n\t", 2);
	putstr_fd("./fractol mandelbrot\n\t", 2);
	putstr_fd("./fractol julia\n\t", 2);
	putstr_fd("./fractol julia <real> <imaginary>\n", 2);
}

/*
ft_strncmp:		compares 2 strings for n amount of bytes

Parameters:		const char *s1
				const char *s2
				size_t n

return:			int (0 if equal, other if different)

How it works:	the function parses through both s1 and s2 strings with a while
				function to compare the values, when a diference is found or n
				has reached its limit or either of the string is finished and
				return the diference
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && (i + 1 < n) && (s1[i] == s2[i]))
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
atod:			converts str into a double.

Parameters:		char *str

return:			double

How it works:	1. skips empty space
				2. goes through signs and sets variable
				3. sets int variable until it finds a '.'
				4. skips point
				5. sets decimal part correctly
				6. return int+decimal * sign
*/
double	atod(char	*str)
{
	long	int_part;
	double	dec_part;
	double	power;
	int		sign;

	int_part = 0;
	dec_part = 0.0;
	power = 1.0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -sign;
	while (*str != '.' && *str)
		int_part = (int_part * 10) + (*str++ - 48);
	if (*str == '.')
		str++;
	while (*str)
	{
		power /= 10;
		dec_part = dec_part + (*str++ - 48) * power;
	}
	return ((int_part + dec_part) * sign);
}
