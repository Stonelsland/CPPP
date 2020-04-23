//
// Created by NOAH on 2020/4/23.
//

#include "Search_Stack.h"

bool Search_Stack::pop(string &elem) {
    if (empty()) return false;
    elem = _search_stack.back();
    _search_stack.pop_back();
    return true;
}

bool Search_Stack::peek(string &elem) {
    if (empty()) return false;
    elem = _search_stack.back();
}

bool Search_Stack::push(const string &elem) {
    if (full()) return false;
    _search_stack.push_back(elem);
    return true;
}

bool Search_Stack::find(string &elem) const {
    vector<string>::const_iterator end_it = _search_stack.end();
    return ::find(_search_stack.begin(), end_it, elem) != end_it;
}

int Search_Stack::count(string &elem) const {
    return ::count(_search_stack.begin(), _search_stack.end(), elem);
}

int main() {

    Search_Stack searchStack;
    string str;

    while (cin >> str && !searchStack.full())
        searchStack.push(str);
    if (searchStack.empty()) {
        cout << "\n" << "no string";
        return 0;
    }
    searchStack.peek(str);
    if (searchStack.size() == 1 && searchStack.empty()) {
        cout << "\n" << "no string";
        return 0;
    }
    cout << "\n" << "Read in " << searchStack.size() << " strings\n";

    cout << "\n" << "search: " << endl;
    cin.clear();
    cin.sync();
    cin >> str;

    bool found = searchStack.find(str);
    int count = found ? searchStack.count(str) : 0;

    cout << str << (found ? " is" : " isn\'t") << " in the searchStack\n";
    if (found)cout << "It occurs " << count << " times\n";

}