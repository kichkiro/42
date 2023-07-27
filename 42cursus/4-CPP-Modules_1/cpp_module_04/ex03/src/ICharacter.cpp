/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:52:04 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/27 22:53:12 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

// SFM ------------------------------------------------------------------------>

ICharacter::ICharacter(void) {
    cout << "ICharacter - Default Constructor" << endl;
}

ICharacter::ICharacter(const ICharacter &src) {
    cout << "ICharacter - Copy Constructor" << endl;
}

ICharacter &ICharacter::operator=(const ICharacter &rs) {
    cout << "ICharacter - Default Assignment Operator" << endl;
    return *this;
}

ICharacter::~ICharacter() {
    cout << "ICharacter - Default Destructor" << endl;
}
