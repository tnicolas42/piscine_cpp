/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NameModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 12:08:04 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/27 14:31:54 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NameModule.hpp"
#include <pwd.h>
#include <unistd.h>

std::string NameModule::_titles[NB_ATTRIBUTES_NAME] = 
{
	"hostname",
	"username"
};

NameModule::NameModule(void) : AAttributeListMonitorModule("Hostname / Username", NB_ATTRIBUTES_NAME, NameModule::_titles)
{
	
}

NameModule::NameModule(NameModule const &instance): AAttributeListMonitorModule(instance)
{
	
}

NameModule::~NameModule(void)
{
	
}

NameModule &	NameModule::operator=(NameModule const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

bool	NameModule::retrieveData(void)
{
	char tab[100];

	gethostname(tab, 100);
	uid_t uid = getuid();
	struct passwd *pass = getpwuid(uid);
	_attributes[0].setValue(tab);
	_attributes[1].setValue(pass->pw_name);
	return true;
}