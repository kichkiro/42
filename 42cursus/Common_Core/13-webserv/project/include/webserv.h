/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   webserv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:51:48 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/10 14:19:26 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <vector>
#include <fstream>
#include <exception>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <arpa/inet.h>
#include <poll.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

#include "utils.hpp"

// Using ---------------------------------------------------------------------->

using std::string;
using std::stringstream;
using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::vector;
using std::getline;
using std::streampos;
using std::exception;
using std::remove;
using std::ofstream;
using std::runtime_error;

// Enum ----------------------------------------------------------------------->

enum HTTP_METHOD {
	GET,
	POST,
	DELETE
};

// Classes -------------------------------------------------------------------->

#include "Directive.hpp"

// #include "Autoindex.hpp"
// #include "ClientMaxBodySize.hpp"
// #include "ErrorPage.hpp"
// #include "Http.hpp"
// #include "Include.hpp"
// #include "Index.hpp"
// // #include "LimitExcept.hpp"
// #include "Listen.hpp"
// // #include "Location.hpp"
// #include "Rewrite.hpp"
// #include "Root.hpp"
// #include "Server.hpp"
// class Server;
// #include "ServerName.hpp"

#include "Log.h"
#include "Error.h"
