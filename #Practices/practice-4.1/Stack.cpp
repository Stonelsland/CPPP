//
// Created by NOAH on 2020/4/22.
//

#include "Stack.h"

bool Stack::pop(string &elem) {
    if (empty()) return false;
    elem = _stack.back();
    _stack.pop_back();
    return true;
}

bool Stack::peek(string &elem) {
    if (empty())return false;
    elem = _stack.back();
    return true;
}

bool Stack::push(const string &elem) {
    if (full())return false;
    _stack.push_back(elem);
    return true;
}

int main() {
    Stack stack;
    string str;

    while (cin >> str && !stack.full())
        stack.push(str);
    if (stack.empty()) {
        cout << "\n" << "no string";
        return 0;
    }
    stack.peek(str);
    if (stack.size() == 1 && stack.empty()) {
        cout << "\n" << "no string";
        return 0;
    }
    cout << "\n" << "read in " << stack.size() << " strings!\n"
         << "The strings, in reverse order: \n";

    while (stack.size())
        if (stack.pop(str))
            cout << str << " ";
    cout << "\n"<<"There are now " << stack.size() << " elements in the stack!\n";
}