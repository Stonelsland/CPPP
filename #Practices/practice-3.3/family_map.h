//
// Created by NOAH on 2020/4/20.
//

#ifndef FAMILY_MAP_H
#define FAMILY_MAP_H

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

typedef vector<string> vstring;
map<string, vstring> families;

class family_map {
};

void populate_map(ifstream &nameFile,
                  map<string, vstring> &families) {
    string textline;
    while (getline(nameFile, textline)) {
        string first_name;
        vector<string> last_name;
        string::size_type
                pos = 0,
                prev_pos = 0,
                text_size = textline.size();
        //前一个pos是接收找到目标后返回的位置
        //后一个pos是查找目标的起始位置，为上个循环执行结果++后得到
        while ((pos = textline.find_first_of(' ', pos))
               != string::npos) {
            string::size_type end_pos = pos - prev_pos;
            if (!prev_pos) {
                first_name = textline.substr(prev_pos, end_pos);
            } else {
                last_name.push_back(textline.substr(prev_pos, end_pos));
            }
            prev_pos = ++pos;
        }

        if (prev_pos < text_size) {
            last_name.push_back(textline.substr(prev_pos, pos - prev_pos));
        }

        if (!families.count(first_name))
            families[first_name] = last_name;
        else cerr << first_name << " family is already exist!";
    }
}

// 展示map内容
void display_map(const map<string, vstring> &families, ostream &os) {
    map<string, vstring>::const_iterator
            it = families.begin(),
            end_it = families.end();

    while (it != end_it) {
        os << "The " << it->first << " family ";
        if (it->second.empty())
            os << "has no children !\n";
        else {
            os << "has " << it->second.size() << "children: ";
            vector<string>::const_iterator
                    iter = it->second.begin(),
                    end_iter = it->second.end();

            while (iter != end_iter) {
                os << *iter << " ";
                ++iter;
            }
            os << endl;
        }
        ++it;
    }
}

//查询map
void query_map(const string &family,
               const map<string, vstring> &families) {
    map<string, vstring>::const_iterator
            it = families.find(family);

    if (it == families.end()) {
        cout << "Sorry The " << family
             << " is not currently entered.\n";
        return;
    }
    cout << "The " << family;
    if (!it->second.size())
        cout << " has no members \n";
    else {
        cout << " has " << it->second.size() << " children: ";
        vector<string>::const_iterator
                iter = it->second.begin(),
                end_iter = it->second.end();

        while (iter != end_iter) {
            cout << *iter << " ";
            ++iter;
        }
        cout << endl;
    }

}

#endif //FAMILY_MAP_H
