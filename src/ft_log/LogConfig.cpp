/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LogConfig.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:47:37 by sliziard          #+#    #+#             */
/*   Updated: 2025/11/27 23:43:29 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>

#include "LogConfig.hpp"
#include "Logger.hpp"

// ============================================================================
// Global configuration API
// ============================================================================

namespace ft_log
{

void	setLevel(e_log_level level)
{
	Logger::instance().setLevel(level);
}

e_log_level	getLevel(void)
{
	return (Logger::instance().level());
}

void	enableCategory(const std::string &category)
{
	Logger::instance().enableCategory(category);
}

void	disableCategory(const std::string &category)
{
	Logger::instance().disableCategory(category);
}

bool	isCategoryEnabled(const std::string &category)
{
	return (Logger::instance().categoryEnabled(category));
}

void	setOutputStream(std::ostream &os)
{
	Logger::instance().setOutputStream(os);
}

void	setColorEnabled(bool enabled)
{
	Logger::instance().setUseColor(enabled);
}

bool	isColorEnabled(void)
{
	return (Logger::instance().useColor());
}

// ============================================================================
// Runtime query and logging helpers
// ============================================================================

bool	enabled(const std::string &category, e_log_level level)
{
	return (Logger::instance().enabled(category, level));
}

std::ostream	&log(const std::string &category, e_log_level level)
{
	Logger	&instance = Logger::instance();

	if (instance.enabled(category, level))
		return (instance.log(category, level));
	return Logger::g_nullStream;
}

std::string	color(const std::string &text, const char *ansiCode)
{
	return (Logger::instance().colorize(text, ansiCode));
}

} // namespace ft_log

