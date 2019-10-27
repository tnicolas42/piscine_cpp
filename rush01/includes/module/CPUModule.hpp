/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:40:16 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/27 13:35:09 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP

# include <iostream>
# include "AAttributeListMonitorModule.hpp"

# define NB_ATTRIBUTES_CPU 5

class CPUModule : public AAttributeListMonitorModule
{
	public:
		CPUModule(void);
		CPUModule(CPUModule const &instance);
		CPUModule &operator=(CPUModule const &rhs);
		virtual ~CPUModule(void);
		virtual bool retrieveData(void);

	private:
	
		std::string _getStringFromQuery(int queryTitle, int queryEntry);
		std::string _getIntFromQuery(int queryTitle, int queryEntry);
		std::string _getNbCPUS(void);
		std::string _getModel(void);
		std::string _getClock(void);
		std::string _getEndianness(void);
		static std::string _titles[NB_ATTRIBUTES_CPU];
};

#endif
