/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATitleMonitorModule.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:48:12 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/26 13:18:23 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATitleMonitorModule.hpp"


ATitleMonitorModule::ATitleMonitorModule(const std::string name) : 
	AMonitorModule(name, "TitleMonitorModule"), _value("unknown")
{
	
}

ATitleMonitorModule::ATitleMonitorModule(ATitleMonitorModule const &instance) : AMonitorModule(instance)
{
	*this = instance;
}

ATitleMonitorModule::~ATitleMonitorModule(void)
{
	
}

ATitleMonitorModule &	ATitleMonitorModule::operator=(ATitleMonitorModule const &rhs)
{
	_value = rhs._value;
	return *this;
}

std::string	ATitleMonitorModule::getValue(void) const
{
	return (this->_value);
}

void	ATitleMonitorModule::setValue(std::string value)
{
	this->_value = value;
}
