/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Directive.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:59:36 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/22 17:26:30 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using std::string;
using std::ifstream;
using std::vector;
using std::map;

// Defines -------------------------------------------------------------------->

#define HTTP                    0;
#define SERVER                  1;
#define LOCATION                2;
#define LIMIT_EXCEPT            3;
#define LISTEN                  4;
#define ROOT                    5;
#define SERVER_NAME             6;
#define INCLUDE                 7;
#define ERROR_PAGE              8;
#define CLIENT_MAX_BODY_SIZE    9;
#define ALIAS                   10;
#define INDEX                   11;
#define AUTOINDEX               12;

// Classes -------------------------------------------------------------------->

class Directive {
    private:
        string         _type;
        vector<string> _allowed_context;
        bool           _is_context;

    protected:
        virtual void _parse(string raw_value) = 0;
        
    public:
        Directive(void);
        virtual ~Directive() ;

        void set_type(string type);
        void set_allowed_context(vector<string> allowed_context);
        void set_is_context(bool is_context);
        string get_type(void);
        vector<string> get_allowed_context(void);
        bool get_is_context(void);
};

class Http : public Directive {
    private:
        vector<Directive*> _value;

        void _parse(string raw_value);

    public:
        Http(void);
        Http(string raw_value);
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

