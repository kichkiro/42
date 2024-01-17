/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:27:11 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/17 16:08:08 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv) {
    if (argc < 2) {
        cerr << "Usage: ./PmergeMe <unsigned int> <unsigned int> <...>" << endl;
        exit(EXIT_FAILURE);
    }
    this->_run(argc, argv);
}

PmergeMe::PmergeMe(const PmergeMe &src) {
    *this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rs) {
    this->_v_seq = rs._v_seq;
    this->_d_seq = rs._d_seq;
    return *this;
}

PmergeMe::~PmergeMe(void) {}

void PmergeMe::_run(int argc, char **argv) {
    clock_t start, end;

    parser(argc, argv, this->_v_seq);
    parser(argc, argv, this->_d_seq);
    display_sequence(this->_v_seq, "Before");
    start = clock();
    ford_johnson(this->_v_seq, 0, argc - 2);
    end = clock();
    display_sequence(this->_v_seq, "After");
    this->_display_time(argc - 1, "std::vector", start, end);
    start = clock();
    ford_johnson(this->_d_seq, 0, argc - 2);
    end = clock();
    this->_display_time(argc - 1, "std::deque", start, end);
}

void PmergeMe::_display_time(int n, string type, clock_t start, clock_t end) {
    double timer;

    timer = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1e6;
    cout << "Time to process a range of " << n << " elements with " << type << 
        " : " << timer << " us" << endl;
}
