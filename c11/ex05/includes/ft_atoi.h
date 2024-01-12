/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:29:37 by yeohong           #+#    #+#             */
/*   Updated: 2022/10/17 10:01:41 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ATOI_H
# define FT_ATOI_H

int	is_space(char *str);
int	is_number(char *str);
int	ft_atoi(char *str);

# define DIV_MSG "Stop : division by zero\n"
# define MOD_MSG "Stop : modulo by zero\n"

#endif 
