/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Directives.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:59:36 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/23 15:06:20 by kichkiro         ###   ########.fr       */
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

// Classes -------------------------------------------------------------------->

class Directive {
    protected:
        string _type;
        bool   _is_context;

        virtual void _parse(ifstream &raw_value) = 0;

    public:
        Directive(void);
        virtual ~Directive();
        
        static const char *_directives[];

        static void router(
            vector<Directive *> &value,
            string context,
            string directive,
            ifstream &file
        );
};

class Http : public Directive {
    private:
        vector<Directive *> _value;

        void _parse(ifstream &raw_value);

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

class Include : public Directive {
    private:
        string _value;

        void _parse(string raw_value);

    public:
        Include(string raw_value);
        ~Include();
};

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

