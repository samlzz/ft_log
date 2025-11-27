/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LogScope.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:39:07 by sliziard          #+#    #+#             */
/*   Updated: 2025/11/28 00:16:21 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LOG_LOG_SCOPE_HPP
# define FT_LOG_LOG_SCOPE_HPP

# include "AnsiColor.hpp"
# include "Logger.hpp"

// ============================================================================
// Defines to set colors used in LogScope
// ============================================================================

# ifndef FT_LOG_SCOPE_ENTER_COLOR
#  define FT_LOG_SCOPE_ENTER_COLOR	FT_LOG_COLOR_RED
# endif
# ifndef FT_LOG_SCOPE_EXIT_COLOR
#  define FT_LOG_SCOPE_EXIT_COLOR	FT_LOG_COLOR_RED
# endif
# ifndef FT_LOG_SCOPE_NAME_COLOR
#  define FT_LOG_SCOPE_NAME_COLOR	FT_LOG_COLOR_BLUE
# endif

// ============================================================================
// ft_log::LogScope - RAII tracing helper
// ============================================================================

namespace ft_log
{

/**
 * @brief RAII helper that logs enter/exit of a scope.
 */
class LogScope
{
public:
	LogScope(const char *category, const char *name, e_log_level level);
	~LogScope(void);

private:
	const char	*_category;
	const char	*_name;
	e_log_level	_level;
	bool		_enabled;

	LogScope();
	LogScope(const LogScope &other);
	LogScope	&operator=(const LogScope &other);
};

} // namespace ft_log

#endif // FT_LOG_LOG_SCOPE_HPP

