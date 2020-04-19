//
// Created by NOAH on 2020/4/18.
//

#include "iterator_demo.h"

int main() {

    map<string, int> words;
    string tword;
    while (cin >> tword) words[tword]++;
    map<string, int>::iterator it = words.begin();
    for (; it != words.end(); ++it) {
        cout << "key: " << it->first
             << " value: " << it->second << endl;
    }
}