/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:58:08 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/31 21:32:30 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// SFM ------------------------------------------------------------------------>

MateriaSource::MateriaSource(void) {
    cout << "MateriaSource - Default Constructor" << endl;
    for (int i = 0; i < 4; i++)
        this->_learned[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src) : IMateriaSource(src) {
    cout << "MateriaSource - Copy Constructor" << endl;
    *this = src;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rs) {
    cout << "MateriaSource - Default Assignment Operator" << endl;
    for (int i = 0; i < 4; i++)
		this->_learned[i] = rs._learned[i];
    return *this;
}

MateriaSource::~MateriaSource() {
    cout << "MateriaSource - Default Destructor" << endl;
    for (int i = 0; i < 4; i++) {
        if (this->_learned[i])
            delete this->_learned[i];
    }
}

// Methods -------------------------------------------------------------------->

void MateriaSource::learnMateria(AMateria *materia) {
    for (int i = 0; i < 4; i++) {
        if (!this->_learned[i]) {
            this->_learned[i] = materia;
            break;
        }
    }
}

AMateria *MateriaSource::createMateria(string const &type) {
    for (int i = 0; i < 4; i++) {
        if (this->_learned[i]->getType() == type)
            return this->_learned[i]->clone();
    }
    return 0;
}
