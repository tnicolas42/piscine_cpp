/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Attribute.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 12:29:03 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/26 16:45:24 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Attribute.hpp"

Attribute::Attribute(void): _name("title"), _value("N/A")
{
	
}

Attribute::Attribute(std::string name, std::string value) : _name(name), _value(value)
{
	
}

Attribute::Attribute(Attribute const &instance)
{
	*this = instance;
}

Attribute::~Attribute(void)
{
	
}

Attribute &	Attribute::operator=(Attribute const &rhs)
{
	_name = rhs._name;
	_value = rhs._value;
	return *this;
}

std::string	Attribute::getName() const
{
	return (this->_name);
}

std::string	Attribute::getValue() const
{
	return (this->_value);
}

void	Attribute::setName(std::string const name)
{
	this->_name = name;
}

void	Attribute::setValue(std::string const value)
{
	this->_value = value;
}

// std::ostream &	operator<<(std::ostream &o, Attribute const &instance)
// {
// 	o << instance.getName() << instance.getValue();
// 	return o;
// }
