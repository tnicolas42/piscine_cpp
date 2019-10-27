/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:34:16 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/27 13:35:09 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RAMModule.hpp"
#include <sys/sysctl.h>
#include <unistd.h>
#include "sys/types.h"
#include <mach/host_info.h>
#include <mach/mach.h>
#include <mach/vm_statistics.h>


std::string RAMModule::_titles[NB_ATTRIBUTES_RAM] = 
{
	"physical memory",
	"user memory used",
	"memory page size",
	"swap memory"
};

RAMModule::RAMModule(void) : AAttributeListMonitorModule("RAM", NB_ATTRIBUTES_RAM,
	RAMModule::_titles)
{
	
}

RAMModule::RAMModule(RAMModule const &instance) : AAttributeListMonitorModule(instance)
{
	
}

RAMModule::~RAMModule(void)
{
	
}

RAMModule &	RAMModule::operator=(RAMModule const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

bool	RAMModule::retrieveData(void)
{
	struct vm_statistics64 stats;
	mach_port_t	host;
	natural_t	count   = HOST_VM_INFO64_COUNT;

	host = mach_host_self();
	xsw_usage vmusage = {0,0,0,0,0};
	size_t size = sizeof(vmusage);
	if (sysctlbyname("vm.swapusage", &vmusage, &size, NULL, 0) != 0)
		return true;
	long long int totMemSize = 0;
	size_t length = sizeof(totMemSize);
	int mib [] = { CTL_HW, HW_MEMSIZE };
	if (-1 == sysctl(mib, 2, nullptr, &length, NULL, 0))
		return false;
	if (-1 == sysctl(mib, 2, &totMemSize, &length, NULL, 0))
		return false;
	if (host_statistics64(host, HOST_VM_INFO64, (host_info64_t)&stats, &count) != KERN_SUCCESS)
		return true;
	int64_t used = (stats.free_count + stats.active_count + stats.inactive_count + stats.wire_count + stats.compressor_page_count) * getpagesize();
	_attributes[0].setValue(AMonitorModule::serializeToString(totMemSize / 1000000000) + " Gbytes");
	_attributes[1].setValue(AMonitorModule::serializeToString(used/ 1000000) + " Mbytes");
	_attributes[2].setValue(AAttributeListMonitorModule::_getIntFromQuery(CTL_HW, HW_PAGESIZE) + " bytes");
	_attributes[3].setValue(AMonitorModule::serializeToString(vmusage.xsu_used) + " bytes");
	return true;
}