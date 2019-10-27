/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:03:01 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/27 14:34:03 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileModule.hpp"
#include <sys/sysctl.h>
#include <unistd.h>

std::string FileModule::_titles[NB_ATTRIBUTES_FILE] = 
{
	"max number of files",
	"number of kernel files",
	"max number of files / process",
	"core file"
};

FileModule::FileModule(void) : AAttributeListMonitorModule("Files", NB_ATTRIBUTES_FILE, FileModule::_titles)
{
	
}

FileModule::FileModule(FileModule const &instance) : AAttributeListMonitorModule(instance)
{
	
}

FileModule::~FileModule(void)
{
	
}

FileModule &	FileModule::operator=(FileModule const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}	

bool	FileModule::retrieveData(void)
{
	_attributes[0].setValue(AAttributeListMonitorModule::_getIntFromQuery(CTL_KERN, KERN_MAXFILES));
	_attributes[1].setValue(AAttributeListMonitorModule::_getIntFromQueryName("kern.num_files"));
	_attributes[2].setValue(AAttributeListMonitorModule::_getIntFromQuery(CTL_KERN, KERN_MAXFILESPERPROC));
	_attributes[3].setValue(AAttributeListMonitorModule::_getStringFromQueryName("kern.corefile"));
	return true;
}