/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:52:04 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/31 21:29:54 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

// SFM ------------------------------------------------------------------------>

ICharacter::ICharacter(void) {
    cout << "ICharacter - Default Constructor" << endl;
}

ICharacter::ICharacter(const ICharacter &src) {
    cout << "ICharacter - Copy Constructor" << endl;
    *this = src;
}

ICharacter::~ICharacter() {
    cout << "ICharacter - Default Destructor" << endl;
}
