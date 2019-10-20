/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <francis.leroy@protonmail.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:22:55 by fle-roy           #+#    #+#             */
/*   Updated: 2019/10/20 18:55:46 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_HPP
#define COLORS_HPP

#define NO_COLOR 			-1
#define COLOR_WHITE_PAIR	1
#define COLOR_RED_PAIR		2
#define COLOR_GREEN_PAIR	3
#define COLOR_BLUE_PAIR		4
#define COLOR_STAR			5
#define COLOR_ORANGE_PAIR	6

#include <ncurses.h>

bool	initColors(void);

#endif /* COLORS_HPP */
