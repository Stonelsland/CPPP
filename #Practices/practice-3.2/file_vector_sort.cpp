//
// Created by NOAH on 2020/4/19.
//

#include "file_vector_sort.h"

void display(const vector<string> &,
             ostream &, int len);
void display_vector(const vector<string> &,
             ostream &, int len);
int main() {
    ifstream ifile("../micheal.txt");
    ofstream ofile("../micheal.sort");

    if (!ifile || !ofile) {
        cerr << "open file error" << endl;
        return -1;
    }

    vector<string> text;
    string word;

    while (ifile >> word) text.push_back(word);
    sort(text.begin(), text.end(), file_vector_sort());
    // display(text, ofile);
    display_vector(text,ofile);
}