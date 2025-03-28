/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:58:12 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/31 21:30:33 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

// SFM ------------------------------------------------------------------------>

IMateriaSource::IMateriaSource(void) {
    cout << "IMateriaSource - Default Constructor" << endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource &src) {
    cout << "IMateriaSource - Copy Constructor" << endl;
    *this = src;
}

IMateriaSource::~IMateriaSource() {
    cout << "IMateriaSource - Default Destructor" << endl;
}

