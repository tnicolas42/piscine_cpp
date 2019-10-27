/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfoModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 12:45:50 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/27 13:35:09 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OSInfoModule.hpp"
#include <sys/utsname.h>

std::string OSInfoModule::_titles[NB_ATTRIBUTES_OSINFO] = {
	"system name",
	"release",
	"version"
};

OSInfoModule::OSInfoModule(void) : AAttributeListMonitorModule("OS Informations",
	NB_ATTRIBUTES_OSINFO, OSInfoModule::_titles)
{
	
}

OSInfoModule::OSInfoModule(OSInfoModule const &instance) : AAttributeListMonitorModule(instance)
{
	
}

OSInfoModule::~OSInfoModule(void)
{
	
}

OSInfoModule &	OSInfoModule::operator=(OSInfoModule const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

bool	OSInfoModule::retrieveData(void)
{
	struct utsname uts;

	uname(&uts);
	_attributes[0].setValue(uts.sysname);
	_attributes[1].setValue(uts.release);
	_attributes[2].setValue(uts.version);
	return true;
}
