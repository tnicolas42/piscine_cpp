/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NameModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 12:09:30 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/27 13:35:09 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAMEMODULE_HPP
# define NAMEMODULE_HPP

# include <iostream>
# include "AAttributeListMonitorModule.hpp"
# define NB_ATTRIBUTES_NAME 2

class NameModule : public AAttributeListMonitorModule
{
	public:
		NameModule(void);
		NameModule(NameModule const &instance);
		NameModule &operator=(NameModule const &rhs);
		virtual ~NameModule(void);
		virtual bool retrieveData(void);
	private:
		static std::string _titles[NB_ATTRIBUTES_NAME];
};
#endif
