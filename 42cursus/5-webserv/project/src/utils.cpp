/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:41:56 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/25 12:33:27 by kichkiro         ###   ########.fr       */
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

string second_token(const string &str) {
    size_t i;
    
    i = first_token(str).length();
    while (str[i] == 32 || str[i] == 9)
        i++;
    return str.substr(i, str.find_first_of(";") - i);
}
