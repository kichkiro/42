/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:17:08 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/09 12:17:09 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "webserv.h"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define WHITE "\033[37m"

class Log
{
	private:
		Log();
		Log(const Log &src);
		Log &operator=(const Log &src);
		~Log();

		static std::string _timeStamp();
	public:
		static void info(const std::string &message);
		static void error(const std::string &message);
		static void request(HTTP_METHOD method, const std::string &uri);
};
