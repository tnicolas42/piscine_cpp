/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:22:56 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/27 13:35:09 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMEMODULE_HPP
# define TIMEMODULE_HPP

# include <iostream>
# include "ATitleMonitorModule.hpp"

class TimeModule  : public ATitleMonitorModule
{
	public:
		TimeModule(void);
		TimeModule(TimeModule const &instance);
		TimeModule &operator=(TimeModule const &rhs);
		virtual ~TimeModule(void);
		virtual bool retrieveData(void);
};
#endif
