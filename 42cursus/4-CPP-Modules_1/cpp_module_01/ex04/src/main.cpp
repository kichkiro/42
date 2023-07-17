/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:33:13 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/17 12:48:09 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int argc, char **argv)
{
    string infile;
    string outfile;
    string s1;
    string s2;
    string line;
    size_t pos;

    if (argc != 4)
    {
        cout << "usage: ./replace <filename> <s1> <s2>" << endl;
        return 1;
    }

    infile = string(argv[1]);
    outfile = infile + ".replace";
    s1 = string(argv[2]);
    s2 = string(argv[3]);
    ifstream input_file(argv[1]);
    ofstream output_file(outfile.c_str());

    if (input_file.is_open())
    {
        while (getline(input_file, line) && output_file.is_open())
        {
            pos = line.find(s1);
            while (pos != string::npos)
            {
                line.erase(pos, s1.length());
                line.insert(pos, s2);
                cout << line;
                pos = line.find(s1, pos + 1);
            }
            output_file << line << endl;
        }
    }
    else
    {
        cout << "error when opening the file" << endl;
        return 1;
    }

    return 0;
}
