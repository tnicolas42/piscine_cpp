/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceDebris.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <francis.leroy@protonmail.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 13:53:10 by fle-roy           #+#    #+#             */
/*   Updated: 2019/10/20 19:40:06 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPACEDEBRIS_CLASS_HPP
#define SPACEDEBRIS_CLASS_HPP

#include "AScreenRenderedElement.class.hpp"
#include <cstdlib>
#include "Colors.hpp"

class SpaceDebris: public AScreenRenderedElement
{
public:
	SpaceDebris(Screen *sc = nullptr, size_t line = 0, size_t col = 0);
	SpaceDebris(SpaceDebris const &);
	SpaceDebris&	operator=(SpaceDebris const &);
	void			foward();
	bool			update();
	~SpaceDebris();
};

#endif /* SPACEDEBRIS_CLASS_HPP */
