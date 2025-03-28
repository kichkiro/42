/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Directive.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:59:36 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/10 15:57:34 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>
#include <fstream>
#include <vector>
#include <fstream>
#include <string>
#include <dirent.h>
#include <unistd.h>
#include <exception>

#include "utils.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;
using std::vector;
using std::getline;
using std::streampos;
using std::exception;

// Defines -------------------------------------------------------------------->

#define PORT 4242
#define MAX_CONNECTIONS 10
#define TIMEOUT_SEC 5
#define TIMEOUT_USEC 0
#define BUFFER_SIZE 1024

// Class ---------------------------------------------------------------------->

class Directive {
    protected:
        typedef vector<string>::iterator VecStrIt;
        typedef vector<Directive *>::iterator VecDirIt;

        string              _type;
        bool                _is_context;
        vector<string>      _value_inline;
        vector<Directive *> _value_block;

        virtual void _parsing_inline(string raw_value);
        virtual void _parsing_block(ifstream &raw_value);

    public:
        Directive(void);
        virtual ~Directive();

        string              get_type(void) const;
        bool                get_is_context(void) const;
        vector<string>      get_value_inline(void) const;
        vector<Directive *> get_value_block(void) const;
        size_t              get_block_size(void) const;
        size_t              get_inline_size(void) const;

        static const char *_directives[];

        static void router(
            vector<Directive *> &value,
            string context,
            string directive,
            string line,
            ifstream &file
        );

        class WrongContextExc : public exception {
            private:
                virtual const char *what(void) throw() {return "err";}
            public :
                WrongContextExc(string directive, string allow, string wrong) {
                    cerr << "webserv: " << directive << ": this directive " << 
                        "can be used only in: " << allow << " directive/s and "
                        << "not in: " << wrong << endl;
                }
                virtual ~WrongContextExc() throw() {}
        };
};

#include "Alias.hpp"
#include "Autoindex.hpp"
#include "ClientMaxBodySize.hpp"
#include "ErrorPage.hpp"
#include "Http.hpp"
#include "Include.hpp"
#include "Index.hpp"
// #include "LimitExcept.hpp"
#include "Listen.hpp"
// #include "Location.hpp"
#include "Rewrite.hpp"
#include "Root.hpp"
#include "Server.hpp"
class Server;
#include "ServerName.hpp"
