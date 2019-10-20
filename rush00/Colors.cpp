/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <francis.leroy@protonmail.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:24:47 by fle-roy           #+#    #+#             */
/*   Updated: 2019/10/20 18:55:36 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"

bool	initColors(void)
{

	if (COLORS < 3)
		return (false);
	init_color(COLORS - 1, 646, 646, 294);
	init_color(COLORS - 2, 960, 560, 133);
	init_pair(COLOR_WHITE_PAIR, COLOR_WHITE, -1);
	init_pair(COLOR_STAR, COLORS - 1, -1);
	init_pair(COLOR_RED_PAIR, COLOR_RED, -1);
	init_pair(COLOR_GREEN_PAIR, COLOR_GREEN, -1);
	init_pair(COLOR_BLUE_PAIR, COLOR_BLUE, -1);
	init_pair(COLOR_ORANGE_PAIR, COLORS - 2, -1);
	return (true);
}
