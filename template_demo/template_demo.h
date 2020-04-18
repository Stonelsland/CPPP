//
// Created by NOAH on 2020/4/13.
//

#ifndef TEMPLATE_DEMO_H
#define TEMPLATE_DEMO_H

#include <iostream>
#include <vector>
#include <array>

using namespace std;

class template_demo {

};

template<typename elemType>
elemType *find(const vector<elemType> &vec, const elemType value) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == value)return vec[i];
    }
    return 0;
}

template<typename elemType>
inline elemType *begin(const vector<elemType> &vec) {
    return vec.empty() ? 0 : &vec[0];
}

template<typename elemType>
inline elemType *end(const vector<elemType> &vec) {
    return vec.empty() ? 0 : &vec[vec.size + 1];
}

template<typename elemType>
elemType *find(const elemType *first,
               const elemType *last, const elemType &value) {
    if (!first || !last) return 0;
    for (; first != last; ++first) {
        if (*first == value) return first;
    }
    return 0;
}

#endif //TEMPLATE_DEMO_H