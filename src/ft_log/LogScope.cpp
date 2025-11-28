/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LogScope.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 00:00:39 by sliziard          #+#    #+#             */
/*   Updated: 2025/11/28 00:16:34 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/Logger.hpp"
#include "LogScope.hpp"

namespace ft_log {

LogScope::LogScope(const char *category, const char *name, e_log_level level)
	: _category(category), _name(name)
	, _level(level), _enabled(false)
{
	Logger	&instance = Logger::instance();

	if (instance.enabled(_category, _level))
	{
		_enabled = true;
		instance.log(_category, _level)
			<< instance.colorize("enter ", FT_LOG_SCOPE_ENTER_COLOR)
			<< instance.colorize(_name, FT_LOG_SCOPE_NAME_COLOR)
			<< "\n";
	}
}

LogScope::~LogScope(void)
{
	if (!_enabled)
		return;
	Logger	&instance = Logger::instance();
	
	instance.log(_category, _level)
		<< instance.colorize("exit ", FT_LOG_SCOPE_EXIT_COLOR)
		<< instance.colorize(_name, FT_LOG_SCOPE_NAME_COLOR)
		<< "\n";
}

} // namespace ft_log

