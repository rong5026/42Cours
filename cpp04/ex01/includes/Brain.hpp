/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:10:07 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/19 23:50:38 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
    std::string	ideas[100];

public:
    Brain(void);
    Brain(const Brain &source);
    Brain& operator=(const Brain& source);
    ~Brain(void);

};
 
#endif // BRAIN_HPP