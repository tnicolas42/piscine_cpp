/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AScreenElement.class.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <francis.leroy@protonmail.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:44:44 by fle-roy           #+#    #+#             */
/*   Updated: 2019/10/20 16:03:10 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISCREENELEMENT_CLASS_HPP
#define ISCREENELEMENT_CLASS_HPP
#include <cstdlib>
#include <string>

class AScreenElement
{
protected:
	size_t 			_x;
	size_t 			_y;
	size_t 			_width;
	size_t 			_height;
	std::string		_texture;
	int8_t			_color;
	bool			_bold;
public:
	AScreenElement(
		size_t x = 0,
		size_t y = 0,
		size_t width = 1,
		size_t height = 1,
		std::string texture = " ",
		int8_t color = -1);
	AScreenElement(AScreenElement const &);
	AScreenElement&		operator=(AScreenElement const &);
	size_t		getX() const;
	size_t		getY() const;
	size_t		getWidth() const;
	size_t		getHeight() const;
	std::string	getTexture() const;
	int16_t		getRed() const;
	int16_t		getGreen() const;
	int16_t		getBlue() const;
	bool		getBold() const;
	bool		hasColor() const;
	int8_t		getColor() const;
	void		setX(size_t n);
	void		setY(size_t n);
	void		setWidth(size_t n);
	void		setHeight(size_t n);
	void		setTexture(std::string n);
	void		setColor(int8_t n);
	void		setBold(bool v);
	virtual ~AScreenElement();
	virtual bool	update() = 0;  // return false is the object need to be removed
	bool			isColision(AScreenElement const &other) const;
};


#endif /* ISCREENELEMENT_CLASS_HPP */
