/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:32:26 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/14 12:59:42 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>

using std::cout;
using std::endl;
using std::string;

// Class ---------------------------------------------------------------------->

class Weapon
{
	public:
		Weapon(void);
		Weapon(string type);
		~Weapon(void);
		
		const string&	getType(void);
		void			setType(string new_type);

	private:
		string			_type;
};
