/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:24:40 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/27 13:41:12 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TimeModule.hpp"

TimeModule::TimeModule(void) : ATitleMonitorModule("Date")
{
	
}

TimeModule::TimeModule(TimeModule const &instance) : ATitleMonitorModule(instance)
{
	
}

TimeModule::~TimeModule(void)
{
	
}

TimeModule &	TimeModule::operator=(TimeModule const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

bool	TimeModule::retrieveData(void)
{
	time_t     now = time(0);
    struct tm  tstruct;
	char       buf[100];
	tstruct = *localtime(&now);

	strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
    setValue(buf);
	return true;
}