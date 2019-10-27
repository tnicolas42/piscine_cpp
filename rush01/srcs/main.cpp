/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:30:57 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/26 21:44:28 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SystemMonitor.hpp"
#include "IMonitorDisplay.hpp"
#include "SFMLMonitorDisplay.hpp"

int main(int argc, char **argv)
{
	SystemMonitor sm;

	if (sm.init(argc, argv) == false) {
		return 1;
	}
	if (sm.run() == false) {
		return 1;
	}

	return (0);
}
