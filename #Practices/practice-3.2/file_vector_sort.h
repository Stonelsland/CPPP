//
// Created by NOAH on 2020/4/19.
//

#ifndef FILE_VECTOR_SORT_H
#define FILE_VECTOR_SORT_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

class file_vector_sort {
public:
    bool operator()(const std::string &s1,
                    const std::string &s2) {
        return s1.size() < s2.size();
    }
};

template<typename elemType>
void display_vector(const vector<elemType> &vec,
                    ostream &os = cout, int len = 8) {
    typename vector<elemType>::const_iterator iter = vec.begin(), end_it = vec.end();
    // auto iter = vec.begin(), end_it = vec.end(); // C++ 11

    int elem_int = 1;
    while (iter != end_it)
        os << *iter++
           << (!(elem_int++ % len) ? '\n' : ' ');
}

void display(const vector<string> &vec,
             ostream &os = cout, int len = 8) {

    vector<string>::const_iterator
            iter = vec.begin(),
            end_it = vec.end();


    int elem_int = 1;
    while (iter != end_it)
        os << *iter++
           << (!(elem_int++ % len) ? '\n' : ' ');
}


#endif //FILE_VECTOR_SORT_H
