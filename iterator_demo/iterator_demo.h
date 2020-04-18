//
// Created by NOAH on 2020/4/14.
//

#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class iterator {

};
template <typename IteratorType,typename elemType>
IteratorType
find(IteratorType first,IteratorType last,
        const elemType &value){
    for (; first != last ; ++first) {
        if(value == *first)
            return first;
    }
    return last;
}

int count_occurs(const vector<int> &vec,int val){
    vector<int>::const_iterator iter = vec.begin();
    int occurs_count = 0;
    while ((iter = find(iter,vec.end(),val)) != vec.end()){
        ++occurs_count;
        //这里的++iter 是为了保证'不对任一元素进行两次以上的检视'
        ++iter;
    }
    return occurs_count;
}

#endif //ITERATOR_H
