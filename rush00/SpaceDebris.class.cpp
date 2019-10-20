/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceDebris.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <francis.leroy@protonmail.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 13:58:00 by fle-roy           #+#    #+#             */
/*   Updated: 2019/10/20 19:40:06 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpaceDebris.class.hpp"

SpaceDebris::SpaceDebris(Screen *sc, size_t line, size_t col):
	AScreenRenderedElement(sc, col, line, 1, 1, "*", COLOR_STAR) {};

SpaceDebris::SpaceDebris(SpaceDebris const &o)
{
	*this = o;
}

SpaceDebris&	SpaceDebris::operator=(SpaceDebris const &o)
{
	if (this == &o)
		return (*this);
	(AScreenRenderedElement&)*this = (AScreenRenderedElement const &)o;
	return (*this);
}

SpaceDebris::~SpaceDebris() {}

void	SpaceDebris::foward()
{
	this->setY(this->getY() + 1);
}

bool	SpaceDebris::update()
{
	this->foward();
	if (this->getScreen() == nullptr)
		return (false);
	return (this->getY() < this->getScreen()->getGameSizeY());
}
