/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:41:56 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/23 11:53:59 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

bool str_in_array(const char *str, const char **arr) {
    for (size_t i = 0; arr[i]; ++i) {
        if (!strcmp(str, arr[i]))
            return true;
    }
    return false;
}
