/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:08:26 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/14 13:38:13 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class   Harl
{
private:
    void	debug(void);
    void	info(void);
    void	warning(void);
    void	error(void);

public:
    Harl(void);
    ~Harl(void);
    void	complain(std::string level);

};

typedef void (Harl::*t_harl) (void);
