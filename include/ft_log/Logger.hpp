/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:33:18 by sliziard          #+#    #+#             */
/*   Updated: 2025/11/27 23:00:40 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LOG_LOGGER_HPP
# define FT_LOG_LOGGER_HPP

# include <string>
# include <set>
# include <ostream>

// ============================================================================
// ft_log::Logger - core logger implementation
// ============================================================================

namespace ft_log
{

/**
 * @brief Logging severity level.
 */
enum e_log_level
{
	LOG_TRACE = 0,
	LOG_DEBUG,
	LOG_INFO,
	LOG_WARN,
	LOG_ERROR,
	LOG_OFF
};

/**
 * @brief Core logger singleton.
 *
 * This class holds all runtime logging state:
 *  - global log level,
 *  - enabled categories,
 *  - output stream,
 *  - use color flag.
 *
 * It is not meant to be used directly in most code. Prefer the public
 * facade functions declared in LogConfig.hpp.
 */
class Logger
{
public:
	static Logger	&instance(void);

	// ---------------------------------------------------------------------
	// Configuration
	// ---------------------------------------------------------------------

	void			setLevel(e_log_level level);
	e_log_level		level(void) const;

	void			enableCategory(const std::string &category);
	void			disableCategory(const std::string &category);
	bool			categoryEnabled(
						const std::string &category) const;

	void			setOutputStream(std::ostream &os);
	std::ostream	&stream(void) const;

	void			setUseColor(bool state);
	bool			useColor(void) const;

	// ---------------------------------------------------------------------
	// Query and logging
	// ---------------------------------------------------------------------

	bool			enabled(const std::string &category,
						e_log_level level) const;

	std::ostream	&log(const std::string &category,
						e_log_level level);

	/**
	 * @brief Colorize text using the given ANSI code.
	 *
	 * If colors are disabled, this returns the plain text unchanged.
	 */
	std::string		colorize(const std::string &text,
						const char *ansiCode) const;

private:
	Logger(void);
	Logger(const Logger &);
	Logger	&operator=(const Logger &);

	e_log_level				_level;
	std::set<std::string>	_categories;
	std::ostream			*_out;
	bool					_useColor;
};

} // namespace ft_log

#endif // FT_LOG_LOGGER_HPP

