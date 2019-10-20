/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <francis.leroy@protonmail.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 12:11:21 by fle-roy           #+#    #+#             */
/*   Updated: 2019/10/20 19:40:46 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_CLASS_HPP
#define SCREEN_CLASS_HPP
#include <ncurses.h>
#include "Colors.hpp"
#include "AScreenElement.class.hpp"
#define INVISIBLE_CURSOR 0
#define SCORE_STR "Score : "
#define SCORE_STR_SIZE 8
#define HP_STR			"HP : "
#define HP_STR_SIZE		5
#define DEBRIS_NB 25

class Screen
{
private:
	bool		_init;
	WINDOW		*_wgame;
	WINDOW		*_wscore;
	size_t		_score;
	size_t		_hp;
	void		_create_windows();
public:
	Screen();
	Screen(Screen const &);
	Screen operator=(Screen const &);
	void	updateScore(size_t score);
	size_t	getScore() const;
	void	incrementScore(size_t nb);
	void	decrementScore(size_t nb);
	int		getUserInput();
	void	deleteElement(AScreenElement &el);
	void	displayElement(AScreenElement &el);
	void	display();
	bool	check_size();
	bool	init();
	void	deinit();
	size_t	getHP() const;
	void	setHP(size_t hp);
	bool	decrementHP();
	size_t	getGameSizeX();
	size_t	getGameSizeY();
	~Screen();
};



#endif /* SCREEN_CLASS_HPP */
