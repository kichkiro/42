/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:27:18 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/17 13:27:19 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <deque>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::deque;
using std::atoi;
using std::invalid_argument;

// Class ---------------------------------------------------------------------->

class PmergeMe {
    public:
        PmergeMe(int argc, char **argv);
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &rs);
        ~PmergeMe(void);

        void run(void);

    private:
        vector<unsigned int> _sequence;
        
        vector<unsigned int> _parser(int argc, char **argv);
        void _display_sequence(const vector<unsigned int> &seq, const string &label);
        void _display_time(const string &type, clock_t start, clock_t end);
};

//******************************************************************************

template <typename T>
void insertion_sort(void) {
    // TODO
}

template <typename T>
void merge_insert_sort(void) {
    // TODO
}

//******************************************************************************
