/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:45:33 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/27 13:35:09 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CPUModule.hpp"
#include <sys/sysctl.h>
#include <string>

std::string CPUModule::_titles[NB_ATTRIBUTES_CPU] = 
{
	"machine model",
	"machine class",
	"number of cores",
	"clock frequency",
	"endianness",
};

CPUModule::CPUModule(void) : AAttributeListMonitorModule("CPU", NB_ATTRIBUTES_CPU,
	CPUModule::_titles)
{
	
}

CPUModule::CPUModule(CPUModule const &instance) : AAttributeListMonitorModule(instance)
{
	
}

CPUModule::~CPUModule(void)
{
	
}

CPUModule &	CPUModule::operator=(CPUModule const &rhs)
{
	(void)rhs;
	return *this;
}

std::string CPUModule::_getEndianness()
{
	int mib [] = { CTL_HW, HW_BYTEORDER };
	int value;
	size_t length = sizeof(value);
	if (-1 == sysctl(mib, 2, &value, &length, NULL, 0))
		return "Undefined";
	if (value == 1234)
	{
		return "little endian";
	}
	else if (value == 4321)
		return "big endian";
	else
		return "Undefined";
}

std::string CPUModule::_getClock()
{
	int mib [] = { CTL_KERN, KERN_CLOCKRATE };
	struct clockinfo info;
	size_t length = sizeof(info);
	if (-1 == sysctl(mib, 2, &info, &length, NULL, 0))
		return "Undefined";
	return AMonitorModule::serializeToString(info.hz) + " hz";
}

bool	CPUModule::retrieveData(void)
{
	_attributes[0].setValue(AAttributeListMonitorModule::_getStringFromQuery(CTL_HW, HW_MODEL));
	_attributes[1].setValue(AAttributeListMonitorModule::_getStringFromQuery(CTL_HW, HW_MACHINE));
	_attributes[2].setValue(AAttributeListMonitorModule::_getIntFromQuery(CTL_HW, HW_NCPU));
	_attributes[3].setValue(_getClock());
	_attributes[4].setValue(_getEndianness());
	// std::cout << "model: " << _attributes[0].getValue() << std::endl;
	// std::cout << "machine: " << _attributes[1].getValue() << std::endl;
	// std::cout << "nbcores: " << _attributes[2].getValue() << std::endl;
	// std::cout << "clock frequency: " << _attributes[3].getValue() << std::endl;
	// std::cout << "endianness: " << _attributes[4].getValue() << std::endl;
	return true;
}