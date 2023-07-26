/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 00:17:11 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/26 09:17:35 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// SFM ------------------------------------------------------------------------>

Brain::Brain(void) {
    cout << "Brain       - Default Constructor" << endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = "";
}

Brain::Brain(const Brain &src) {
    cout << "Brain       - Default Copy Constructor" << endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = src.ideas[i];
}

Brain &Brain::operator=(const Brain &rs) {
    if (this != &rs) {
        for (int i = 0; i < 100; i++)
            ideas[i] = rs.ideas[i];
    }
    return *this;
}

Brain::~Brain(void) {
    cout << "Brain       - Default Destructor" << endl;
}
