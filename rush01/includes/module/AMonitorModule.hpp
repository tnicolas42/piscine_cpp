/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:42:24 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/27 13:35:09 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMONITORMODULE_HPP
# define AMONITORMODULE_HPP

# include <iostream>
# include "IMonitorModule.hpp"

class AMonitorModule : public IMonitorModule
{
	public:
		AMonitorModule(const std::string &name, const std::string &type);
		AMonitorModule(AMonitorModule const &instance);
		AMonitorModule &operator=(AMonitorModule const &rhs);
		virtual ~AMonitorModule(void);
		std::string getName(void) const;
		std::string getType(void) const;
		virtual bool retrieveData(void) = 0;

	
		
	private:
		AMonitorModule(void);
		std::string _name;
		std::string _type;
	protected:
		static std::string serializeToString(long long int);
};

#endif