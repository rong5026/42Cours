/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:45:51 by yeohong           #+#    #+#             */
/*   Updated: 2022/12/15 13:28:40 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_seperate(char c, va_list arg_ptr)
{
	if (c == 'c')
		return (ft_put_char(va_arg(arg_ptr, int)));
	else if (c == 's')
		return (ft_put_str(va_arg(arg_ptr, char *)));
	else if (c == 'p')
		return (ft_put_p(va_arg(arg_ptr, unsigned long long)));
	else if (c == 'd' || c == 'i')
		return (ft_put_d_i(va_arg(arg_ptr, int)));
	else if (c == 'u')
		return (ft_put_u(va_arg(arg_ptr, int)));
	else if (c == 'x' || c == 'X')
		return (ft_put_x(va_arg(arg_ptr, int), c));
	else if (c == '%')
		return (ft_put_char('%'));
	else
		return (0);
}

int	ft_input_parsing(const char *input, va_list arg_ptr)
{
	int		total;

	total = 0;
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			if (!input)
				return (total);
			total += ft_seperate(*input, arg_ptr);
		}
		else
			total += ft_put_char(*input);
		input++;
	}
	return (total);
}

int	ft_printf(const char *input, ...)
{
	va_list	arg_ptr;
	int		total;

	va_start(arg_ptr, input);
	total = ft_input_parsing(input, arg_ptr);
	va_end(arg_ptr);
	return (total);
}
