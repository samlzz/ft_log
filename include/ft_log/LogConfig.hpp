/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LogConfig.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:36:11 by sliziard          #+#    #+#             */
/*   Updated: 2025/11/27 23:01:22 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_CONFIG_HPP
# define LOG_CONFIG_HPP

# include <string>
# include <ostream>

# include "internal/Logger.hpp"

// ============================================================================
// ft_log - public configuration and helper API
// ============================================================================

namespace ft_log
{

// ---------------------------------------------------------------------------
// Global configuration API
// ---------------------------------------------------------------------------

/**
 * @brief Set the global minimum log level.
 *
 * Log with a level below this threshold will be ignored.
 */
void		setLevel(e_log_level threshold);

/**
 * @brief Get the current global log level.
 */
e_log_level	getLevel(void);

/**
 * @brief Enable a logging category (e.g. "peg.parser").
 */
void		enableCategory(const std::string &category);

/**
 * @brief Disable a logging category.
 */
void		disableCategory(const std::string &category);

/**
 * @brief Check if a category is currently enabled.
 */
bool		isCategoryEnabled(const std::string &category);

/**
 * @brief Set the output stream used for logging (default: std::cerr).
 */
void		setOutputStream(std::ostream &os);

/**
 * @brief Enable or disable ANSI color output globally.
 */
void		setColorEnabled(bool enabled);

/**
 * @brief Check whether ANSI color output is enabled.
 */
bool		isColorEnabled(void);

// ---------------------------------------------------------------------------
// Runtime query and logging helpers
// ---------------------------------------------------------------------------

/**
 * @brief Check if logging is enabled for the category and level.
 */
bool		enabled(const std::string &category,
				e_log_level level = LOG_TRACE);

/**
 * @brief Get the output stream for the given category and level.
 *
 */
std::ostream	&log(const std::string &category,
				e_log_level level = LOG_TRACE);

/**
 * @brief Return a colorized version of the given text.
 *
 * If color output is disabled, the plain text is returned.
 */
std::string	color(const std::string &text, const char *ansiCode);

} // namespace ft_log

#endif // LOG_CONFIG_HPP

