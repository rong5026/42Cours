/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:37:55 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/11/13 15:40:06 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {
}

Weapon::~Weapon() {
}

const std::string &Weapon::getType(void) {
	return this->type;
}

void Weapon::setType(std::string type) {
	this->type = type;
}
