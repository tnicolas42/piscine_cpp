/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AScreenElement.class.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <francis.leroy@protonmail.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:57:50 by fle-roy           #+#    #+#             */
/*   Updated: 2019/10/20 19:40:46 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AScreenElement.class.hpp"

AScreenElement::AScreenElement(
		size_t x,
		size_t y,
		size_t width,
		size_t height,
		std::string texture,
		int8_t color):
		_x(x),
		_y(y),
		_width(width),
		_height(height),
		_texture(texture),
		_color(color),
		_bold(false) {}

AScreenElement::AScreenElement(AScreenElement const &o)
{
	*this = o;
}

AScreenElement&		AScreenElement::operator=(AScreenElement const &o)
{
	if (this == &o)
		return (*this);
	this->setHeight(o.getHeight());
	this->setWidth(o.getWidth());
	this->setX(o.getX());
	this->setY(o.getY());
	this->setTexture(o.getTexture());
	this->setColor(o.getColor());
	this->setBold(o.getBold());
	return (*this);
}

AScreenElement::~AScreenElement() {}

size_t		AScreenElement::getX() const
{
	return (this->_x);
}

size_t		AScreenElement::getY() const
{
	return (this->_y);
}

size_t		AScreenElement::getWidth() const
{
	return (this->_width);
}

size_t		AScreenElement::getHeight() const
{
	return (this->_height);
}

std::string	AScreenElement::getTexture() const
{
	return (this->_texture);
}

void		AScreenElement::setX(size_t n)
{
	this->_x = n;
}

void		AScreenElement::setY(size_t n)
{
	this->_y = n;
}

void		AScreenElement::setWidth(size_t n)
{
	if (n < 1)
		n = 1;
	this->_width = n;
}

void		AScreenElement::setHeight(size_t n)
{
	if (n < 1)
		n = 1;
	this->_height = n;
}

void		AScreenElement::setTexture(std::string n)
{
	this->_texture = n;
}

int8_t		AScreenElement::getColor() const
{
	return (this->_color);
}

void		AScreenElement::setColor(int8_t n)
{
	this->_color = n;
}
bool		AScreenElement::hasColor() const
{
	return (this->_color > 0);
}

bool		AScreenElement::isColision(AScreenElement const &other) const {
	bool collisionX = getX() + getWidth() > other.getX() &&
        other.getX() + other.getWidth() > getX();

    bool collisionY = getY() + getHeight() > other.getY() &&
        other.getY() + other.getHeight() > getY();

	return collisionX && collisionY;
}

bool		AScreenElement::getBold() const
{
	return (this->_bold);
}

void		AScreenElement::setBold(bool n)
{
	this->_bold = n;
}


