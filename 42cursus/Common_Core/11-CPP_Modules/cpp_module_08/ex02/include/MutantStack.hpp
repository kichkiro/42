/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:16:22 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/04 13:45:59 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <stack>
#include <iterator>

using std::stack;

// Class ---------------------------------------------------------------------->

template <typename T>
class MutantStack : public stack<T> {
    public:
        MutantStack(void);
        MutantStack(const typename stack<T>::container_type &c);
        ~MutantStack(void);

        typedef typename stack<T>::container_type::iterator iterator;
        iterator begin();
        iterator end();
};

#include "MutantStack.tpp"
