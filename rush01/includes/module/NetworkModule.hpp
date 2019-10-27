/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:52:24 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/27 13:35:09 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKMODULE_HPP
# define NETWORKMODULE_HPP

# include <iostream>
# include "AAttributeListMonitorModule.hpp"

# define NB_ATTRIBUTES_NETWORK 3

class NetworkModule : public AAttributeListMonitorModule
{
	public:
		NetworkModule(void);
		NetworkModule(NetworkModule const &instance);
		NetworkModule &operator=(NetworkModule const &rhs);
		virtual ~NetworkModule(void);
		virtual bool retrieveData(void);

	private:
		static std::string _titles[NB_ATTRIBUTES_NETWORK];

};

#endif
