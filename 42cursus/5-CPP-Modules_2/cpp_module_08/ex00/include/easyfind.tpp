/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:16:39 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/08 15:24:25 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
bool easyfind(T &container, int value) {
    for (size_t i = 0; i < container.size(); i++) {
        if (value == container[i])
            return true;
    }
    throw out_of_range("Value not find!");
}
