/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:27:18 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/04 17:35:47 by kichkiro         ###   ########.fr       */
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

// Class ---------------------------------------------------------------------->

class PmergeMe {
    private:
        vector<int> _v_seq;
        deque<int> _d_seq;

        void _run(int argc, char **argv);
        void _display_time(int n, string type, clock_t start, clock_t end);
        
    public:
        PmergeMe(int argc, char **argv);
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &rs);
        ~PmergeMe(void);
};

// Templates ------------------------------------------------------------------>

template <typename T>
void parser(int argc, char **argv, T &container) {
    int value;

    for (int i = 1; i < argc; ++i) {
        value = atoi(argv[i]);
        if (value < 0) {
            cerr << "Error" << endl;
            exit(EXIT_FAILURE);
        }
        container.push_back(value);
    }
}

template <typename T>
void insertion_sort(T &sequence, int beg, int end) {
    int current_idx, current_elem;

    for (int i = beg + 1; i <= end; i++) {
        current_elem = sequence[i];
        current_idx = i - 1;
        while (current_idx >= beg && sequence[current_idx] > current_elem) {
            sequence[current_idx + 1] = sequence[current_idx];
            current_idx--;
        }
        sequence[current_idx + 1] = current_elem;
    }
}

template <typename T>
void merge_sort(T &seq, int beg, int mid, int end) {
    int i, j, k, n1, n2;
    T beg_half(seq.begin() + beg, seq.begin() + mid + 1);
    T end_half(seq.begin() + mid + 1, seq.begin() + end + 1);
    
    i = 0;
    j = 0;
    k = beg;
    n1 = mid - beg + 1;
    n2 = end - mid;
    while (i < n1 && j < n2)
        seq[k++] = (beg_half[i] <= end_half[j]) ? beg_half[i++] : end_half[j++];
    while (i < n1)
        seq[k++] = beg_half[i++];
    while (j < n2)
        seq[k++] = end_half[j++];
}

template <typename T>
void ford_johnson(T &seq, int beg, int end) {
    int mid;

    if (end - beg <= 5)
        insertion_sort(seq, beg, end);
    else {
        mid = beg + (end - beg) / 2;
        ford_johnson(seq, beg, mid);
        ford_johnson(seq, mid + 1, end);
        merge_sort(seq, beg, mid, end);
    }
}

template <typename T>
void display_sequence(const T &seq, const string &label) {
    cout << label << ": ";
    for (size_t i = 0; i < seq.size(); ++i)
        cout << seq[i] << " ";
    cout << endl;
}
