/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:30:36 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/02 13:07:52 by kichkiro         ###   ########.fr       */
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
