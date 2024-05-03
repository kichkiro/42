/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:16:39 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/03 18:44:41 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

// TODO
template <typename T>
int easyfind(const T& container, int value) {
    typename T::const_iterator it = std::find(container.begin(), 
                                              container.end(), value);
    if (it != container.end())
        return *it;
    else
        return -1;
}
