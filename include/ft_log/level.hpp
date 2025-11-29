/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 19:13:11 by sliziard          #+#    #+#             */
/*   Updated: 2025/11/29 21:38:19 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEVEL_HPP
# define LEVEL_HPP

#include <ostream>

/**
 * @brief Logging severity level.
 */
enum e_log_level
{
	FTLOG_TRACE = 0,
	FTLOG_DEBUG,
	FTLOG_INFO,
	FTLOG_WARN,
	FTLOG_ERROR,
	FTLOG_OFF
};

std::ostream	&operator<<(std::ostream &os, e_log_level lvl);

#endif

