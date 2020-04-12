//
// Created by NOAH on 2020/4/11.
//

#ifndef TEST_FIBO_SEQ_H
#define TEST_FIBO_SEQ_H

#include <iostream>
#include <vector>

using namespace std;

class fibo_seq {
public:
};

inline bool is_size_ok(int size){
    const int max_size = 1024;
    if(size <0 || size > max_size){
        cerr << "invalid size:" << size << endl;
        return false;
    }
    return true;
}

const vector<int>* fibo_seq(int size){
    static vector<int> elems;
    if(!is_size_ok(size)) return 0;
    for (int i = elems.size(); i < size ; ++i) {
        if(i == 0 || i== 1) elems.push_back(1);
        else elems.push_back(elems[i-1]+elems[i-2]);
    }
    return &elems;
}

inline bool fibo_elem(int pos, int &elem) {

    const vector<int> *pseq = fibo_seq(pos);
    if(!pseq){
        elem = 0;
        return false;
    }
    elem = (*pseq)[pos-1];
    return true;
}


#endif //TEST_FIBO_SEQ_H
