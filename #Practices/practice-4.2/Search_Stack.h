//
// Created by NOAH on 2020/4/23.
//

#ifndef SEARCH_STACK_H
#define SEARCH_STACK_H


#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Search_Stack {
public:
    bool pop(string &elem);

    bool peek(string &elem);

    bool push(const string &);

    bool find(string &elem) const;

    int count(string &elem) const;

    bool empty() const { return _search_stack.empty(); };

    int size() const { return _search_stack.size(); };

    bool full() const { return _search_stack.size() == _search_stack.max_size(); };


private:
    vector<string> _search_stack;
};


#endif //SEARCH_STACK_H
