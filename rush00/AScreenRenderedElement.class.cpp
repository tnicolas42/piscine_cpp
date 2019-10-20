/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AScreenRenderedElement.class.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <francis.leroy@protonmail.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 11:06:03 by fle-roy           #+#    #+#             */
/*   Updated: 2019/10/20 19:40:46 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AScreenRenderedElement.class.hpp"


AScreenRenderedElement::AScreenRenderedElement(
		Screen *sc,
		size_t x,
		size_t y,
		size_t width,
		size_t height,
		std::string texture,
		int8_t color) :
AScreenElement(x, y, width, height, texture, color), _screen(sc) {}

AScreenRenderedElement::AScreenRenderedElement(AScreenRenderedElement const &o)
{
	*this = o;
}

AScreenRenderedElement::~AScreenRenderedElement() {}

AScreenRenderedElement&	AScreenRenderedElement::operator=(AScreenRenderedElement const &o)
{
	if (this == &o)
		return (*this);
	(AScreenElement&)*this = (AScreenElement const &)o;
	this->setScreen(o.getScreen());
	return (*this);
}

Screen		*AScreenRenderedElement::getScreen() const
{
	return (this->_screen);
}

void		AScreenRenderedElement::setScreen(Screen *sc)
{
	this->_screen = sc;
}

