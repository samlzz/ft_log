/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 21:37:11 by sliziard          #+#    #+#             */
/*   Updated: 2025/11/29 21:41:12 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>

#include "level.hpp"

std::ostream &operator<<(std::ostream &os, e_log_level lvl)
{
	switch (lvl)
	{
		case FTLOG_TRACE: os << "TRACE"; break;
		case FTLOG_DEBUG: os << "DEBUG"; break;
		case FTLOG_INFO:  os << "INFO"; break;
		case FTLOG_WARN:  os << "WARN"; break;
		case FTLOG_ERROR: os << "ERROR"; break;
		case FTLOG_OFF:   break;
	}
	return os;
}

