/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAttributeListMonitorModule.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 12:25:59 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/26 12:27:38 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AATTRIBUTELISTMONITORMODULE_HPP
# define AATTRIBUTELISTMONITORMODULE_HPP

# include <iostream>
# include "AMonitorModule.hpp"
# include "Attribute.hpp"
# include <vector>

class AAttributeListMonitorModule : public AMonitorModule
{
	public:
		AAttributeListMonitorModule(std::string name, int nbAttributes, std::string *titles);
		AAttributeListMonitorModule(AAttributeListMonitorModule const &instance);
		AAttributeListMonitorModule &operator=(AAttributeListMonitorModule const &rhs);
		virtual ~AAttributeListMonitorModule(void);
		const std::vector<Attribute> &getAttributes(void) const;

	private:

		AAttributeListMonitorModule(void);
	protected:
		std::vector<Attribute> _attributes;
		static std::string _getStringFromQuery(int queryTitle, int queryEntry);
		static std::string _getIntFromQuery(int queryTitle, int queryEntry);
		static std::string _getIntFromQueryName(const char *query);
		static std::string _getStringFromQueryName(const char *query);


};
std::ostream &operator<<(std::ostream &o, AAttributeListMonitorModule const &instance);

#endif
