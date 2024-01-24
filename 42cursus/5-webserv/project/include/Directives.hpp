/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Directives.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:59:36 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/24 17:11:29 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>
#include <fstream>
#include <vector>
#include <fstream>
#include <string>

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
        string _type;
        bool   _is_context;

        virtual void _parsing(ifstream &raw_value) = 0;

    public:
        Directive(void);
        virtual ~Directive();

        static const char *_directives[];

        static void router(
            vector<Directive *> &value,
            string context,
            string directive,
            streampos prev_pos,
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
        string _value;
        // vector<string> _value;
        
        void _first_parsing(string raw_value, vector<string> &parsed_content);
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
        vector<Directive *> _value;

        void _parsing(ifstream &raw_value);

    public:
        Http(string context);
        Http(ifstream &raw_value, string context);
        ~Http();
};

// class Server : public Directive {
//     private:

//     public:

// };

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

