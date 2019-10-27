/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:32:19 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/27 13:35:09 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMMODULE_HPP
# define RAMMODULE_HPP

# include <iostream>
# include "AAttributeListMonitorModule.hpp"

# define NB_ATTRIBUTES_RAM 4

class RAMModule : public AAttributeListMonitorModule
{
	public:
		RAMModule(void);
		RAMModule(RAMModule const &instance);
		RAMModule &operator=(RAMModule const &rhs);
		virtual			~RAMModule(void);
		virtual bool	retrieveData(void);
	private:
		static std::string _titles[NB_ATTRIBUTES_RAM];
};
#endif
