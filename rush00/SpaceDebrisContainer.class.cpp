/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceDebrisContainer.class.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <francis.leroy@protonmail.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:36:38 by fle-roy           #+#    #+#             */
/*   Updated: 2019/10/20 19:40:46 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpaceDebrisContainer.class.hpp"
#include "SpaceDebris.class.hpp"

SpaceDebrisContainer::SpaceDebrisContainer(Screen *sc): AContainer(sc), _nb(0) {}

SpaceDebrisContainer::SpaceDebrisContainer(SpaceDebrisContainer const &o)
{
	*this = o;
}

SpaceDebrisContainer&	SpaceDebrisContainer::operator=(SpaceDebrisContainer const &o)
{
	if (this == &o)
		return (*this);
	(AScreenElement&)*this = (AScreenElement const &)o;
	this->_nb = o._nb;
	return (*this);
}

SpaceDebrisContainer::~SpaceDebrisContainer() {}

void	SpaceDebrisContainer::create(size_t n)
{
	this->_nb = n;
	if (this->_nb > this->getMaxElement())
		this->_nb = this->getMaxElement();
	for (size_t i = 0; i < this->_nb ; i++)
		if (this->getElement(i) == nullptr)
		{
			this->setElement(i, new SpaceDebris(
				this->getScreen(),
				rand() % this->getScreen()->getGameSizeY(),
				rand() % this->getScreen()->getGameSizeX()));
			this->getScreen()->displayElement(*this->getElement(i));
		}
}

size_t	SpaceDebrisContainer::getNbDebris()
{
	return (this->_nb);
}


void	SpaceDebrisContainer::update()
{
	AScreenElement	*el;
	if (!this->getScreen())
		return ;
	for (size_t i = 0; i < this->_nb ; i++)
	{
		el = this->getElement(i);
		if (el == nullptr)
		{
			this->setElement(i,
				new SpaceDebris(this->getScreen(), 0, rand() % this->getScreen()->getGameSizeX()));
			el = this->getElement(i);
		}
		this->getScreen()->deleteElement(*el);
		if (!this->getElement(i)->update())
		{
			this->delElement(i);
			this->setElement(i,
				new SpaceDebris(this->getScreen(), 0, rand() % this->getScreen()->getGameSizeX()));
		}
		el = this->getElement(i);
		this->getScreen()->displayElement(*el);
	}
}
