/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LogScope.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:39:07 by sliziard          #+#    #+#             */
/*   Updated: 2025/11/27 22:45:22 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LOG_LOG_SCOPE_HPP
# define FT_LOG_LOG_SCOPE_HPP

# include <string>

# include "LogConfig.hpp"

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
	LogScope(const char *category, const char *name,
		e_log_level level)
		: _category(category)
		, _name(name)
		, _level(level)
		, _enabled(false)
	{
		if (ft_log::enabled(_category, _level))
		{
			_enabled = true;
			ft_log::log(_category, _level)
				<< "enter " << _name << "\n";
		}
	}

	~LogScope(void)
	{
		if (_enabled)
		{
			ft_log::log(_category, _level)
				<< "exit " << _name << "\n";
		}
	}

private:
	const char	*_category;
	const char	*_name;
	e_log_level	_level;
	bool		_enabled;
};

} // namespace ft_log

#endif // FT_LOG_LOG_SCOPE_HPP

