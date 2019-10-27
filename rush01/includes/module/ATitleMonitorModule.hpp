/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATitleMonitorModule.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:45:21 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/26 13:20:19 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATITLEMONITORMODULE_HPP
# define ATITLEMONITORMODULE_HPP

# include <iostream>
# include "AMonitorModule.hpp"


class ATitleMonitorModule : public AMonitorModule
{
	public:
		ATitleMonitorModule(void);
		ATitleMonitorModule(const std::string name);
		ATitleMonitorModule(ATitleMonitorModule const &instance);
		ATitleMonitorModule &operator=(ATitleMonitorModule const &rhs);
		virtual ~ATitleMonitorModule(void);
		std::string getValue(void) const;
		void setValue(std::string value);

	private:
		std::string _value;
};

#endif
