/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:17:02 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/09 12:45:34 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Log.h"

std::string Log::_timeStamp() {
	std::time_t t = std::time(0);
	std::tm *now = std::localtime(&t);
	std::stringstream ss;
	ss << "[" << (now->tm_year + 1900)
		<< "-" << std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
		<< "-" << std::setw(2) << std::setfill('0') << now->tm_mday
		<< " " << std::setw(2) << std::setfill('0') << now->tm_hour
		<< ":" << std::setw(2) << std::setfill('0') << now->tm_min
		<< ":" << std::setw(2) << std::setfill('0') << now->tm_sec << "]";
	return (ss.str());
}

void Log::info(const std::string &message) {
	std::cout << BLUE << _timeStamp() << " [INFO]\t"
		<< WHITE << message << std::endl;
}

void Log::error(const std::string &message) {
	std::cout << RED << _timeStamp() << " [ERROR]\t"
		<< WHITE << message << std::endl;
}

void Log::request(HTTP_METHOD method, const std::string &uri) {
	std::string methodString;
	switch (method) {
		case GET:
			methodString = "GET";
			break;
		case POST:
			methodString = "POST";
			break;
		case DELETE:
			methodString = "DELETE";
			break;
		default:
			methodString = "UNKNOWN";
			break;
	}
	std::cout << GREEN << _timeStamp() << " [" << methodString << "]\t"
		<< WHITE << uri << std::endl;
}
