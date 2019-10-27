/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UptimeModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 13:29:35 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/27 14:33:44 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UptimeModule.hpp"
#include <sys/sysctl.h>
#include <ctime>

UptimeModule::UptimeModule(void) : ATitleMonitorModule("Uptime")
{
	
}

UptimeModule::UptimeModule(UptimeModule const &instance) : ATitleMonitorModule(instance)
{
	
}

UptimeModule::~UptimeModule(void)
{
	
}

UptimeModule &	UptimeModule::operator=(UptimeModule const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

bool	UptimeModule::retrieveData(void)
{
	int hours;
	int minutes;
	int seconds;

	struct timeval boottime;
    size_t len = sizeof(boottime);
    int mib[2] = { CTL_KERN, KERN_BOOTTIME };
    if(sysctl(mib, 2, &boottime, &len, NULL, 0) < 0 )
        return true;
    time_t bsec = boottime.tv_sec, csec = time(NULL);
    long long res = difftime(csec, bsec);
	
	if (res < 60)
		setValue(AMonitorModule::serializeToString(res) + "seconds");
	else if (res < 60 * 60)
		setValue(AMonitorModule::serializeToString(res / 60) + "minutes");
	else if (res < 60 * 60 * 24)
	{
		hours = res / (60 * 60);
		minutes = (res - (hours * 60 * 60)) / 60; 
		seconds = (res - (hours * 60 * 60)) - (minutes * 60); 
		setValue(AMonitorModule::serializeToString(hours) + " " + (hours == 1 ? "hour" : "hours") + ", " +
			AMonitorModule::serializeToString(minutes) + " " + (minutes == 1 ? "minute" : "minutes") + " and " + 
				AMonitorModule::serializeToString(seconds) + " " + (seconds == 1 ? "second" : "seconds"));
	}
	return true;
}