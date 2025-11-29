/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:49:51 by sliziard          #+#    #+#             */
/*   Updated: 2025/11/29 03:00:09 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>

#include "AnsiColor.hpp"
#include "internal/Logger.hpp"

namespace ft_log
{

// ============================================================================
// NullBuffer/NullStream
// ============================================================================

Logger::NullBuffer	Logger::_nullBuffer;
std::ostream		Logger::_nullStream(&_nullBuffer);

// ============================================================================
// Construction
// ============================================================================

Logger::Logger(void)
	: _level(LOG_INFO)
	, _categories()
	, _out(&std::cerr)
	, _useColor(true)
{}

Logger::Logger(const Logger &other)
	: _level(other._level)
	, _categories(other._categories)
	, _out(other._out)
	, _useColor(other._useColor)
{}

Logger	&Logger::operator=(const Logger &other)
{
	if (this != &other)
	{
		_level = other._level;
		_categories = other._categories;
		_out = other._out;
		_useColor = other._useColor;
	}
	return (*this);
}

Logger	&Logger::instance(void)
{
	static Logger	instance;

	return (instance);
}

// ============================================================================
// Accessors
// ============================================================================

void			Logger::setLevel(e_log_level level)	{ _level = level; }
e_log_level		Logger::level(void) const			{ return _level; }

void			Logger::setStream(std::ostream &os)	{ _out = &os; }
std::ostream	&Logger::stream(void) const			{ return *_out; }

void			Logger::setUseColor(bool enabled)	{ _useColor = enabled; }
bool			Logger::useColor(void) const		{ return _useColor; }

// ============================================================================
// Configuration
// ============================================================================

void	Logger::enableCategory(const std::string &category)
{
	_categories.insert(category);
}

void	Logger::disableCategory(const std::string &category)
{
	std::set<std::string>::iterator	it;

	it = _categories.find(category);
	if (it != _categories.end())
		_categories.erase(it);
}

bool	Logger::categoryEnabled(const std::string &category) const
{
	return (_categories.find(category) != _categories.end());
}

// ============================================================================
// Query and logging
// ============================================================================

bool	Logger::enabled(const std::string &category, e_log_level level) const
{
	return (level >= _level && categoryEnabled(category));
}

std::string	Logger::colorize(const std::string &text, const char *ansiCode) const
{
	if (!_useColor || !ansiCode)
		return (text);
	return (ansiCode + text + FT_LOG_COLOR_RESET);
}

} // namespace ft_log

