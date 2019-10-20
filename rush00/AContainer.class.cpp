/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AContainer.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <francis.leroy@protonmail.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:16:11 by fle-roy           #+#    #+#             */
/*   Updated: 2019/10/20 19:41:11 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AContainer.class.hpp"

AContainer::AContainer(Screen* sc): _screen(sc)
{
	for (size_t i = 0; i < MAX_ELEMENT; i++)
		this->setElement(i, nullptr);
}

AContainer::~AContainer()
{
	for (size_t i = 0; i < MAX_ELEMENT; i++)
		this->delElement(i);
}

AContainer::AContainer(AContainer const &o)
{
	*this = o;
}

AContainer		&AContainer::operator=(AContainer const &o)
{
	if (this == &o)
		return (*this);
	this->_screen = o.getScreen();
	for (size_t i = 0; i < (MAX_ELEMENT); i++)
		this->setElement(i, o.getElement(i));
	return (*this);
}

AScreenElement	*AContainer::getElement(size_t idx) const
{
	if (idx >= MAX_ELEMENT)
		return (this->_elements[MAX_ELEMENT - 1]);
	return (this->_elements[idx]);
}

void			AContainer::setElement(size_t idx, AScreenElement *el)
{
	if (idx >= MAX_ELEMENT)
	{
		this->_elements[MAX_ELEMENT - 1] = el;
		return ;
	}
	this->_elements[idx] = el;
}

size_t			AContainer::getMaxElement(void)
{
	return (MAX_ELEMENT);
}

void			AContainer::delElement(size_t idx)
{
	delete this->_elements[idx];
	this->_elements[idx] = nullptr;
}

Screen			*AContainer::getScreen() const
{
	return (this->_screen);
}

