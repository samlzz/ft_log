/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LogConfig.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:36:11 by sliziard          #+#    #+#             */
/*   Updated: 2026/02/18 14:11:15 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_CONFIG_HPP
# define LOG_CONFIG_HPP

# include <string>
# include <ostream>

# include "level.hpp"

// ============================================================================
// ft_log - public configuration API
// ============================================================================

namespace ft_log
{

// ---------------------------------------------------------------------------
// Global configuration
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

/**
 * @brief Enable or disable level prefixing for log messages.
 */
void		setShowLevel(bool enabled);

/**
 * @brief Check whether level prefixing is currently enabled.
 */
bool		isShowLevelEnabled(void);

/**
 * @brief Enable or disable timestamp prefixing for log messages.
 */
void		setShowTimestamp(bool enabled);

/**
 * @brief Check whether timestamp prefixing is currently enabled.
 */
bool		isShowTimestamp(void);


// ---------------------------------------------------------------------------
// Category control
// ---------------------------------------------------------------------------


/**
 * @brief Enable a category.
 *
 * Enabling a parent category automatically enables all subcategories.
 * (e.g. enableCategory("webserv") enables "webserv.server", etc...)
 */
void		enableCategory(const std::string &category);

/**
 * @brief Disable a logging category.
 *
 * Removes explicit activation only.
 * Does NOT override an enabled parent category.
 */
void		disableCategory(const std::string &category);

/**
 * @brief Returns true if the category or one of its parents is enabled.
 */
bool		isCategoryEnabled(const std::string &category);

} // namespace ft_log

#endif // LOG_CONFIG_HPP

