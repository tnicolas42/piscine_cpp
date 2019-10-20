/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerInput.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <francis.leroy@protonmail.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 14:20:51 by fle-roy           #+#    #+#             */
/*   Updated: 2019/10/20 15:56:04 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYERINPUT_CLASS_HPP
#define PLAYERINPUT_CLASS_HPP

#include "Screen.class.hpp"
#define QUIT ('q')
#define FIRE (' ')
class PlayerInput
{
private:
	bool _left;
	bool _right;
	bool _up;
	bool _down;
	bool _quit;
	bool _fire;
	void	_reset();
public:
	PlayerInput();
	PlayerInput(PlayerInput const &);
	PlayerInput	&operator=(PlayerInput const &);
	void	read(Screen &ms);
	int		getHorizontalDirection();
	int		getVerticalDirection();
	bool	fire();
	bool	quit();
	~PlayerInput();
};

#endif /* PLAYERINPUT_CLASS_HPP */
