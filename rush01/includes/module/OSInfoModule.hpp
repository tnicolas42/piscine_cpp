/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfoModule.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 12:41:27 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/27 13:35:09 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSINFOMODULE_HPP
# define OSINFOMODULE_HPP

# include <iostream>
# include "AAttributeListMonitorModule.hpp"

# define NB_ATTRIBUTES_OSINFO 3

class OSInfoModule : public AAttributeListMonitorModule
{
	public:
		OSInfoModule(void);
		OSInfoModule(OSInfoModule const &instance);
		OSInfoModule &operator=(OSInfoModule const &rhs);
		virtual ~OSInfoModule(void);
		virtual bool retrieveData(void);
	private:
		static std::string _titles[NB_ATTRIBUTES_OSINFO];

};

#endif
