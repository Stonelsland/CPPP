//
// Created by NOAH on 2020/4/14.
//

#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;

class Generic_algorithms {

};

template<typename IteratorType, typename elemType>
IteratorType
find_out(IteratorType first, IteratorType last,
         const elemType &value) {
    for (; first != last; ++first) {
        if (value == *first)
            return first;
    }
    return last;
}

int count_occurs(const vector<int> &vec, int val) {
    vector<int>::const_iterator iter = vec.begin();
    int occurs_count = 0;
    while ((iter = find(iter, vec.end(), val)) != vec.end()) {
        ++occurs_count;
        //这里的++iter 是为了保证'不对任一元素进行两次以上的检视'
        ++iter;
    }
    return occurs_count;
}

/*
 * 标准库提供了两个binder adapter
 * bind1st：将指定值绑定至第一操作数
 * bind2nd：将指定值绑定至第二操作数
 */
vector<int> filter(const vector<int> &vec,
                   int val, less<int> &lt) {
    vector<int> nvec;
    vector<int>::const_iterator iter = vec.begin();
    /*
     * bind2nd(less<int> , val)
     * 会把val绑定于less<int>的第二个参数上
     * 于是，less<int>会将每个元素拿来与val比较
     */
    while ((iter = find_if(iter, vec.end(),
                           bind2nd(lt, val))) != vec.end()) {
        nvec.push_back(*iter);
        iter++;
    }
    return nvec;
}

/*
 * 消除filter与vector的型别关联，使filter泛型化
 * 消除与容器类型的相关性，传入一对iterators[first,last]，
 * 并在参数中增加另一个iterator，用以指定从何处开始复制元素
 */
template<typename InputIterator, typename OutputIterator,
        typename ElemType, typename Comp>
OutputIterator filter(InputIterator first, InputIterator last,
                      OutputIterator opi, const ElemType &val, Comp pred) {
    while ((first = find_if(first, last, bind2nd(pred, val))) != last) {
        cout << "found value: " << *first << endl;
        *opi++ = *first++;
    }
    return opi;
}


#endif //ITERATOR_H
