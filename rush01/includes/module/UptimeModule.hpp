/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UptimeModule.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 13:28:08 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/27 14:26:43 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPTIMEMODULE_HPP
# define UPTIMEMODULE_HPP

# include <iostream>

# include "ATitleMonitorModule.hpp"

class UptimeModule : public ATitleMonitorModule
{
	public:
		UptimeModule(void);
		UptimeModule(UptimeModule const &instance);
		UptimeModule &operator=(UptimeModule const &rhs);
		virtual	~UptimeModule(void);
		virtual bool retrieveData(void);
};
#endif
