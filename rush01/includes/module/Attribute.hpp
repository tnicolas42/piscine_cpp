/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Attribute.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 12:27:54 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/27 12:15:28 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATTRIBUTE_HPP
# define ATTRIBUTE_HPP

# include <string>

class Attribute
{
	public:
		Attribute(void);
		Attribute(std::string name, std::string value);
		Attribute(Attribute const &instance);
		Attribute &operator=(Attribute const &rhs);
		~Attribute(void);

		std::string getName() const;
		std::string getValue() const;
		void setName(std::string const name);
		void setValue(std::string const value);

	private:
		std::string _name;
		std::string _value;
};

std::ostream &	operator<<(std::ostream &o, Attribute const &instance);

#endif
