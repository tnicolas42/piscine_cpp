/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SystemMonitor.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:32:43 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/27 14:22:00 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEMMONITOR_HPP
# define SYSTEMMONITOR_HPP

# include <iostream>
# include <list>
# include <map>
# include "AMonitorDisplay.hpp"
# include "AMonitorModule.hpp"

#define FPS 30
#define LOOP_TIME (1000 / FPS)

#define DEFAULT_WIDTH 1200
#define DEFAULT_HEIGHT 800

#define MAX_SIZE_ELEMENT 30

class SystemMonitor
{
	public:
		SystemMonitor();
		SystemMonitor(SystemMonitor const &instance);
		SystemMonitor &operator=(SystemMonitor const &rhs);
		~SystemMonitor(void);
		bool initModules(std::string const &filename);
		bool init(int argc, char **argv);
		bool run(void);
		bool usage() const;

	private:
		bool _displayAllMonitors(void);
		AMonitorDisplay *_display;
		std::list<AMonitorModule *> _modules;
		std::map<std::string, AMonitorModule*> _modules_list;
};
#endif
