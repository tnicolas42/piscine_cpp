/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AScreenRenderedElement.class.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <francis.leroy@protonmail.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 11:01:24 by fle-roy           #+#    #+#             */
/*   Updated: 2019/10/20 19:40:46 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISCREENRENDEREDELEMENT_CLASS_HPP
#define ISCREENRENDEREDELEMENT_CLASS_HPP
#include "Screen.class.hpp"
#include "AScreenElement.class.hpp"

class Screen;

class AScreenRenderedElement: public AScreenElement
{
protected:
	Screen	*_screen;
public:
	AScreenRenderedElement(
		Screen *sc = nullptr,
		size_t x = 0,
		size_t y = 0,
		size_t width = 1,
		size_t height = 1,
		std::string texture = " ",
		int8_t color = -1);
	AScreenRenderedElement(AScreenRenderedElement const &);
	AScreenRenderedElement		&operator=(AScreenRenderedElement const &);
	void						setScreen(Screen *sc);
	Screen						*getScreen() const;
	~AScreenRenderedElement();
};


#endif /* ISCREENRENDEREDELEMENT_HPP */
