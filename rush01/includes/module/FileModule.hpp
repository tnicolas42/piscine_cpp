/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileModule.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:01:27 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/27 14:38:06 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEMODULE_HPP
# define FILEMODULE_HPP

# define NB_ATTRIBUTES_FILE 4
# include <iostream>
# include "AAttributeListMonitorModule.hpp"

class FileModule : public AAttributeListMonitorModule
{
	public:

		FileModule(void);
		FileModule(FileModule const &instance);
		FileModule &operator=(FileModule const &rhs);
		virtual			~FileModule(void);
		virtual bool	retrieveData(void);

	private:
		static std::string _titles[NB_ATTRIBUTES_FILE];

};
#endif
