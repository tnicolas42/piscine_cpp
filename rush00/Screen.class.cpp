/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <francis.leroy@protonmail.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 12:12:13 by fle-roy           #+#    #+#             */
/*   Updated: 2019/10/20 19:40:46 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Screen.class.hpp"
#include <curses.h>

Screen::Screen(): _init(false), _score(0),_hp(0) {}

bool	Screen::init()
{
	int res = 0;

	if (!initscr())
		res = 1;
	res |= cbreak();
	qiflush();
	res |= keypad(stdscr, true);
	res |= noecho();
	res |= nodelay(stdscr, true);
	res |= notimeout(stdscr, true);
	if (!has_colors() || !can_change_color())
		return (false);
	res |= start_color();
	res |= use_default_colors();
	curs_set(INVISIBLE_CURSOR);
	res |= refresh();
	this->_create_windows();
	timeout(0);
	res |= !initColors();
	this->display();
	this->_init = true;
	return (res == OK);
}

void	Screen::deinit()
{
	this->_init = false;
	endwin();
}

Screen::Screen(Screen const &o)
{
	*this = o;
}

Screen	Screen::operator=(Screen const &o)
{
	if (this == &o)
		return (*this);
	this->_init = false;
	this->_wgame = o._wgame;
	this->_wscore = o._wscore;
	this->_hp = o._hp;
	return (*this);
}

Screen::~Screen()
{
	if (this->_init)
		this->deinit();
}

bool	Screen::check_size()
{
	return (COLS > 50 && LINES > 30); //TODO BETTER
}

size_t	getNbSize(size_t nb)
{
	size_t l;
	if (nb == 0)
		return (1);
	for (l = 0; nb != 0; nb /= 10, l++);
	return (l);
}

void	Screen::updateScore(size_t score)
{
	size_t old_size;
	size_t new_size;

	old_size = SCORE_STR_SIZE + getNbSize(this->_score);
	new_size = SCORE_STR_SIZE + getNbSize(score);
	mvwprintw(this->_wscore, 1, COLS - old_size - 1, "%*s", old_size, " ");
	mvwprintw(this->_wscore, 1, COLS - new_size - 1, "%s%lu", SCORE_STR, score);
	this->_score = score;
}

void	Screen::_create_windows()
{
	this->_wgame = newwin(this->getGameSizeY(), this->getGameSizeX(), 0, 0);
	this->_wscore = newwin(3, this->getGameSizeX(), this->getGameSizeY(), 0);
	box(this->_wscore, '|', '-');
	this->updateScore(0);
}

void	Screen::display()
{
	wrefresh(this->_wgame);
	wrefresh(this->_wscore);
	refresh();
}

size_t	Screen::getGameSizeY()
{
	return (LINES - 3);
}

size_t	Screen::getGameSizeX()
{
	return (COLS);

}

int		Screen::getUserInput()
{
	return (getch());
}

void	Screen::incrementScore(size_t nb)
{
	this->updateScore(this->_score + nb);
}

void	Screen::decrementScore(size_t nb)
{
	if (nb > this->_score)
	{
		this->updateScore(0);
		return ;
	}
	this->updateScore(this->_score - nb);
}

void	Screen::deleteElement(AScreenElement &el)
{
	for (size_t i = 0; i < el.getHeight() ; i++)
		mvwprintw(this->_wgame, el.getY() + i, el.getX(), "%*s", el.getWidth(), " ");
}

void	Screen::displayElement(AScreenElement &el)
{
	std::string to_print;
	if (el.hasColor())
		wattron(this->_wgame, COLOR_PAIR(el.getColor()));
	if (el.getBold())
		wattron(this->_wgame, A_BOLD);
	to_print = el.getTexture();
	to_print.append(std::string(el.getWidth() * el.getHeight()
		- to_print.length(), '%'));
	for (size_t i = 0; i < el.getHeight() ; i++)
		mvwprintw(this->_wgame, el.getY() + i, el.getX(), "%s",
			to_print.substr(i * el.getWidth(), el.getWidth()).c_str());
	if (el.getBold())
		wattroff(this->_wgame, A_BOLD);
	if (el.hasColor())
		wattroff(this->_wgame, COLOR_PAIR(el.getColor()));
}

size_t	Screen::getScore() const
{
	return (this->_score);
}

size_t	Screen::getHP() const
{
	return (this->_hp);
}

void	Screen::setHP(size_t hp)
{
	mvwprintw(this->_wscore, 1, 1, "%*s", hp + HP_STR_SIZE, " ");
	wattron(this->_wscore, COLOR_PAIR(COLOR_RED_PAIR));
	mvwprintw(this->_wscore, 1, 1, "%s%lu", HP_STR, hp);
	wattroff(this->_wscore, COLOR_PAIR(COLOR_RED_PAIR));
	this->_hp = hp;

}

bool	Screen::decrementHP()
{
	if (this->_hp > 0)
		this->setHP(this->getHP() - 1);
	return (this->_hp > 0);
}
