//
// Created by NOAH on 2020/4/20.
//

#include "family_map.h"

void populate_map(ifstream &, map<string, vstring> &);

void display_map(const map<string, vstring> &, ostream &);

void query_map(const string &, const map<string, vstring> &);

int main() {
    map<string, vstring> families;
    ifstream nameFile("../name.txt");

    if (!nameFile) {
        cerr << "open error! ";
        return -1;
    }

    populate_map(nameFile, families);

    string first_name;
    while (1) {
        cout << "Please enter a first name: (q to quit)";
        cin >> first_name;

        if (first_name == "q")break;

        query_map(first_name, families);
    }
    display_map(families, cout);
}
