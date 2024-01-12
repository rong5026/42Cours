/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:52:04 by yeohong           #+#    #+#             */
/*   Updated: 2022/12/13 19:26:21 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_put_char(char c);
int		ft_put_str(char *str);
int		ft_put_u(int number);
int		ft_put_d_i(int number);
int		ft_put_x(int number, char c);
int		ft_put_p(unsigned long long number);
int		get_number_count(long long number);
void	show_reverse(long long number);
int		get_hexnumber_count(unsigned long long number);
void	show_base_reverse(unsigned long long number, char *base);
int		ft_seperate(char c, va_list arg_ptr);
int		ft_input_parsing(const char *input, va_list arg_ptr);
int		ft_printf(const char *input, ...);
#endif 
