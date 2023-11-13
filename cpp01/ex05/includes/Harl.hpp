/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:08:26 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/13 17:35:38 by hong-yeongh      ###   ########.fr       */
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
    Harl();
    ~Harl();
    void	complain(std::string level);

};

typedef void (Harl::*t_harl) (void);
