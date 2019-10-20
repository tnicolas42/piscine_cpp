/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceDebrisContainer.class.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <francis.leroy@protonmail.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:33:38 by fle-roy           #+#    #+#             */
/*   Updated: 2019/10/20 19:41:11 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AContainer.class.hpp"

#ifndef SPACEDEBRISCONTAINER_CLASS_HPP
#define SPACEDEBRISCONTAINER_CLASS_HPP

class SpaceDebrisContainer: public AContainer
{
private:
	size_t		_nb;
public:
	SpaceDebrisContainer(Screen *sc = nullptr);
	SpaceDebrisContainer(SpaceDebrisContainer const &);
	SpaceDebrisContainer&	operator=(SpaceDebrisContainer const &o);
	void	create(size_t n);
	size_t	getNbDebris();
	void	update();
	~SpaceDebrisContainer();
};


#endif /* SPACEDEBRISCONTAINER_CLASS_HPP */
