/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:16:39 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/04 10:36:54 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &cont, int val) {
    typename T::iterator it = std::find(cont.begin(), cont.end(), val);
    if (it != cont.end())
        return it;
    else
        throw runtime_error("Value not found.");
}
