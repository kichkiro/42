/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:16:22 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/09 15:04:03 by kichkiro         ###   ########.fr       */
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
