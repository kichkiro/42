/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:30:36 by kichkiro          #+#    #+#             */
/*   Updated: 2023/12/27 15:55:32 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

using std::cout;
using std::cerr;
using std::endl;
using std::exception;

// Class ---------------------------------------------------------------------->

class Base {
    public:
        virtual ~Base() {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

// Functions ------------------------------------------------------------------>

Base *generate(void);
void identify(Base *p);
void identify(Base &p);
