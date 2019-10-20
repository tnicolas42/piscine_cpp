/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerInput.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <francis.leroy@protonmail.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 14:25:06 by fle-roy           #+#    #+#             */
/*   Updated: 2019/10/20 18:35:40 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlayerInput.class.hpp"
#include <ncurses.h>

PlayerInput::PlayerInput(): _left(false), _right(false), _quit(false), _fire(false) {}

PlayerInput::PlayerInput(PlayerInput const &o)
{
	*this = o;
}

PlayerInput		&PlayerInput::operator=(PlayerInput const &o)
{
	if (this == &o)
		return (*this);
	this->_fire = o._fire;
	this->_left = o._left;
	this->_right = o._right;
	this->_up = o._up;
	this->_down = o._down;
	this->_quit = o._quit;
	return (*this);
}

PlayerInput::~PlayerInput() {}

void			PlayerInput::_reset()
{
	this->_fire = false;
	this->_left = false;
	this->_right = false;
	this->_up = false;
	this->_down = false;
	this->_quit = false;
}

void			PlayerInput::read(Screen &ms)
{
	int		c;

	this->_reset();
	while ((c = ms.getUserInput()) != ERR)
		switch (c)
		{
			case KEY_LEFT:
				this->_left = true;
				break;
			case KEY_RIGHT:
				this->_right = true;
				break;
			case FIRE:
				this->_fire = true;
				break ;
			case KEY_UP:
				this->_up = true;
				break;
			case KEY_DOWN:
				this->_down = true;
				break;
			case QUIT:
				this->_quit = true;
				break;
			default:
				break;
		}
}

int				PlayerInput::getHorizontalDirection()
{
	int res;

	res = 0;
	res += this->_right;
	res -= this->_left;
	return (res);
}

int				PlayerInput::getVerticalDirection()
{
	int res;

	res = 0;
	res += this->_up;
	res -= this->_down;
	return (res);
}

bool			PlayerInput::fire()
{
	return (this->_fire);
}

bool			PlayerInput::quit()
{
	return (this->_quit);
}
