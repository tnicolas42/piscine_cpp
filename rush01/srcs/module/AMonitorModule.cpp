/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMonitorModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:43:05 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/26 19:28:09 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMonitorModule.hpp"
#include <sstream>

AMonitorModule::AMonitorModule(void)
{
	
}

AMonitorModule::AMonitorModule(const std::string &name, const std::string &type): _name(name), _type(type)
{
	
}

AMonitorModule::AMonitorModule(AMonitorModule const &instance)
{
	*this = instance;
}

AMonitorModule::~AMonitorModule(void)
{
	
}

AMonitorModule &	AMonitorModule::operator=(AMonitorModule const &rhs)
{
	_name = rhs._name;
	_name = rhs._type;
	return *this;
}

std::string	AMonitorModule::getName(void) const
{
	return (this->_name);
}



std::string	AMonitorModule::getType(void) const
{
	return (this->_type);
}

std::string	AMonitorModule::serializeToString(long long int a)
{
	 std::stringstream ss;

	ss << a;
	std::string str = ss.str();
	return str;
}