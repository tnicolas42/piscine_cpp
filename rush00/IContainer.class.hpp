/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AContainer.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <francis.leroy@protonmail.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:10:55 by fle-roy           #+#    #+#             */
/*   Updated: 2019/10/19 19:11:52 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AContainer_CLASS_HPP
#define AContainer_CLASS_HPP

#include "AScreenElement.class.hpp"
#include "Screen.class.hpp"
#define MAX_ELEMENT 100


class AContainer
{
protected:
	AScreenElement	*_elements[MAX_ELEMENT];
	Screen			*_screen;

public:
	AContainer(Screen* sc = nullptr);
	AContainer(AContainer const &);
	AContainer		&operator=(AContainer const &);
	AScreenElement *getElement(size_t idx) const;
	void			setElement(size_t idx, AScreenElement *el);
	void			delElement(size_t idx);
	size_t			getMaxElement(void);
	Screen			*getScreen() const;
	virtual void	update() = 0;
	~AContainer();
};

#endif /* AContainer_CLASS_HPP */
