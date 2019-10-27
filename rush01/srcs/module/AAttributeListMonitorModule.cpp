/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAttributeListMonitorModule.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 12:38:34 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/27 15:24:19 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAttributeListMonitorModule.hpp"
#include <sys/sysctl.h>

AAttributeListMonitorModule::AAttributeListMonitorModule(std::string name, int nbAttributes, std::string *titles) :
	AMonitorModule(name, "AttributeListMonitorModule"), _attributes(std::vector<Attribute>(nbAttributes))
{
	int i;

	std::vector<Attribute>::iterator it;
	it = _attributes.begin();
	i = 0;
	while (it != _attributes.end())
	{
		(*it).setName(*(titles + i++));
		it++;
	}
}

AAttributeListMonitorModule::AAttributeListMonitorModule(AAttributeListMonitorModule const &instance) : AMonitorModule(instance)
{
	*this = instance;
}

AAttributeListMonitorModule::~AAttributeListMonitorModule(void)
{
	
}

AAttributeListMonitorModule &	AAttributeListMonitorModule::operator=(AAttributeListMonitorModule const &rhs)
{
	_attributes = rhs._attributes;
	return *this;
}

const std::vector<Attribute> &AAttributeListMonitorModule::getAttributes(void) const
{
	return _attributes;
}



std::string AAttributeListMonitorModule::_getStringFromQuery(int queryTitle, int queryEntry)
{
	int mib [] = { queryTitle, queryEntry };
	char value[200];
	size_t length = sizeof(value);
	if (-1 == sysctl(mib, 2, &value, &length, NULL, 0))
		return "Undefined";
	if (length > 0)
		return std::string(value, length - 1);
	else
		return "N/A";
}

std::string AAttributeListMonitorModule::_getIntFromQuery(int queryTitle, int queryEntry)
{
	int mib [] = { queryTitle, queryEntry };
	long long value = 0;
	size_t length = sizeof(value);
	if (-1 == sysctl(mib, 2, &value, &length, NULL, 0))
		return "Undefined";
	return AMonitorModule::serializeToString(value);
}

std::ostream &	operator<<(std::ostream &o, AAttributeListMonitorModule const &instance)
{
	o << "SIZE:" << instance.getAttributes().size() << std::endl;

	size_t i = 0;
	while (i < instance.getAttributes().size())
	{
		// o << instance.getAttributes()[i] << std::endl;
		i++;
	}
	return o;
}

std::string	AAttributeListMonitorModule::_getIntFromQueryName(const char *queryName)
{
	long long value = 0;
	size_t length = sizeof(value);
	if (-1 == sysctlbyname(queryName, nullptr, &length, NULL, 0))
		return "Undefined";
	if (-1 == sysctlbyname(queryName, &value, &length, NULL, 0))
		return "Undefined";
	return AMonitorModule::serializeToString(value);
}

std::string	AAttributeListMonitorModule::_getStringFromQueryName(const char *queryName)
{
	char value[300];

	size_t length = sizeof(value);
	if (-1 == sysctlbyname(queryName, &value, &length, NULL, 0))
		return "Undefined";
	if (length > 0)
		return std::string(value, length - 1);
	else
		return "N/A";
}