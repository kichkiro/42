/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:41:56 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/24 09:51:27 by kichkiro         ###   ########.fr       */
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

string strip(const string &str) {
    size_t first, last;

    first = str.find_first_not_of(" \t\n\r");
    last = str.find_last_not_of(" \t\n\r");
    if (first == string::npos)
        return "";
    return str.substr(first, last - first + 1);
}

string first_token(const string &str) {
    return str.substr(0, str.find_first_of(" \t\n\r"));
}
