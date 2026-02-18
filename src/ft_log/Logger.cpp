/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:49:51 by sliziard          #+#    #+#             */
/*   Updated: 2026/02/18 13:28:36 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <ctime>
#include <iostream>
#include <ostream>

#include "AnsiColor.hpp"
#include "internal/Logger.hpp"
#include "internal/LevelDisplay.hpp"
#include "level.hpp"

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
	, _showLvl(false)
{}

Logger::Logger(const Logger &other)
	: _level(other._level)
	, _categories(other._categories)
	, _out(other._out)
	, _useColor(other._useColor)
	, _showLvl(other._showLvl)
{}

Logger	&Logger::operator=(const Logger &other)
{
	if (this != &other)
	{
		_level = other._level;
		_categories = other._categories;
		_out = other._out;
		_useColor = other._useColor;
		_showLvl = other._showLvl;
	}
	return *this;
}

Logger	&Logger::instance(void)
{
	static Logger	instance;

	return instance;
}

// ============================================================================
// Accessors
// ============================================================================

void			Logger::setLevel(e_log_level level)	{ _level = level; }
e_log_level		Logger::level(void) const			{ return _level; }

void			Logger::setShowLvl(bool enabled)	{ _showLvl = enabled; }
bool			Logger::showLvl(void) const			{ return _showLvl; }

void			Logger::setShowTimestamp(bool enbl)	{ _showTs = enbl; }
bool			Logger::showTimestamp(void) const	{ return _showTs; }

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

std::ostream	&Logger::log(e_log_level level)
{
	std::ostream	&os = *_out;

	if (_showTs)
		os << '[' << getTimestamp() << "] ";
	if (_showLvl)
		os << '['
			<< colorize(e_levelLabel(level), e_levelColor(level))
			<< "] ";
	return os;
}

std::string	Logger::colorize(const std::string &text, const char *ansiCode) const
{
	if (!_useColor || !ansiCode)
		return (text);
	
	return (std::string(ansiCode) + text + FT_LOG_COLOR_RESET);
}

std::string	Logger::getTimestamp(void)
{
	time_t	now = std::time(NULL);
	std::tm	*tm = std::localtime(&now);

	char buf[20];

	std::memset(buf, 0, sizeof(buf));
	std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", tm);

	return std::string(buf);
}

} // namespace ft_log

