//
// Created by NOAH on 2020/4/19.
//

#include "file_map_set_filter.h"

void init_exclusion_set(set<string> &);

void process_file(map<string, int> &, const set<string> &, ifstream &);

void user_query(map<string, int> &);

void display(const map<string, int> &, ofstream &);

int main() {
    ifstream ifile("../column.txt");
    ofstream ofile("../column.map");
    if ( !ifile || !ofile ) {
        cout << "open file error!"<< endl;
        return -1;
    }

    set<string> exclude_set;
    init_exclusion_set(exclude_set);

    map<string,int> word_count;
    process_file(word_count,exclude_set,ifile);
    user_query(word_count);
    display(word_count,ofile);
}