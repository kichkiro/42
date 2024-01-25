/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Directives.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:59:36 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/25 17:21:04 by kichkiro         ###   ########.fr       */
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

#include "utils.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;
using std::vector;
using std::getline;
using std::streampos;

// Classes -------------------------------------------------------------------->

class Directive {
    protected:
        typedef vector<string>::iterator VecStrIt;
        typedef vector<Directive *>::iterator VecDirIt;

        string              _type;
        bool                _is_context;
        string              _value_inline;
        vector<Directive *> _value_block;

        // virtual void _parsing(ifstream &raw_value) = 0;
        
        virtual void _parsing_inline(ifstream &raw_value);
        virtual void _parsing_block(ifstream &raw_value);

    public:
        Directive(void);
        virtual ~Directive();

        string              get_value_inline(void);
        vector<Directive *> get_value_block(void);

        static const char *_directives[];

        static void router(
            vector<Directive *> &value,
            string context,
            string directive,
            ifstream &file
        );
};

/*!
 * @ref 
    Docs:       https://nginx.org/en/docs/ngx_core_module.html#include
    Syntax:	    include file | mask;
    Default:	———
    Context:	any
 */
class Include : public Directive {
    private:
        // string         _value;
        vector<string> *_ptr_parsed_content;
        
        void _pre_parsing(string raw_value);
        void _parsing(ifstream &raw_value);
        
    public:
        Include(string raw_value, vector<string> &parsed_content);
        ~Include();
};

/*!
 * @ref
    Docs:       https://nginx.org/en/docs/http/ngx_http_core_module.html#http
    Syntax:	    http { ... }
    Default:	———
    Context:	main
 */
class Http : public Directive {
    private:
        // vector<Directive *> _value;

        // void _parsing(ifstream &raw_value);

    public:
        Http(string context);
        Http(ifstream &raw_value, string context);
        ~Http();
};

/*!
 * @ref
    Docs:       https://nginx.org/en/docs/http/ngx_http_core_module.html#server
    Syntax:	    server { ... }
    Default:	———
    Context:	http
 */
class Server : public Directive {
    private:
        // vector<Directive *> _value;

        // void _parsing(ifstream &raw_value);

    public:
        Server(string context);
        Server(ifstream &raw_value, string context);
        ~Server();
};

// class Location : public Directive {
//     private:

//     public:

// };

// class Limit_except : public Directive {
//     private:

//     public:

// };

// class Listen : public Directive {
//     private:

//     public:

// };

// class Root : public Directive {
//     private:

//     public:

// };

// class ServerName : public Directive {
//     private:

//     public:

// };


// class ClientMaxBodySize : public Directive {
//     private:

//     public:

// };

// class Alias : public Directive {
//     private:

//     public:

// };

// class Index : public Directive {
//     private:

//     public:

// };

// class Autoindex : public Directive {
//     private:

//     public:

// };

