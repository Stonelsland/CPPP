//
// Created by NOAH on 2020/4/22.
//

#ifndef EVEN_ODD_FILE_H
#define EVEN_ODD_FILE_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

class even_odd_file {
public:
    bool operator()(int elem) {
        return elem % 2 ? false : true;
    }
};


#endif //EVEN_ODD_FILE_H
