/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:27:11 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/17 13:27:12 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv) {
    if (argc < 2) {
        cerr << "Usage: ./PmergeMe <unsigned int> <unsigned int> <...>" << endl;
        exit(EXIT_FAILURE);
    }
    this->_sequence = this->_parser(argc, argv);
}

PmergeMe::PmergeMe(const PmergeMe &src) {
    *this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rs) {
    this->_sequence = rs._sequence;
    return *this;
}

PmergeMe::~PmergeMe(void) {}

void PmergeMe::run(void) {
    clock_t start;
    clock_t end;

    this->_display_sequence(this->_sequence, "Before");
    start = clock();
    // SORT WITH VECTOR
    end = clock();
    this->_display_sequence(this->_sequence, "After");
    this->_display_time("First Container", start, end);
    start = clock();
    // SORT WITH DEQUE
    end = clock();
    this->_display_time("Second Container", start, end);
}

vector<unsigned int> PmergeMe::_parser(int argc, char **argv) {
    vector<unsigned int> result;
    int                  value;

    for (int i = 1; i < argc; ++i) {
        try {
            value = atoi(argv[i]);
            result.push_back(value);
        }
        catch (const invalid_argument &e) {
            cerr << "Error: Invalid argument - " << argv[i] << endl;
            exit(EXIT_FAILURE);
        }
    }
    return result;
}

void PmergeMe::_display_sequence(const vector<unsigned int> &seq, const string &label) {
    cout << label << ": ";
    for (size_t i = 0; i < seq.size(); ++i)
        cout << seq[i] << " ";
    cout << endl;
}

void PmergeMe::_display_time(const string &type, clock_t start, clock_t end) {
    double timer;

    timer = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1e6;
    cout << "Time to process with " << type << ": " << timer << " us" << endl;
}
