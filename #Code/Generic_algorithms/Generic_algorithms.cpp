//
// Created by NOAH on 2020/4/14.
//

#include "Generic_algorithms.h"

int count_occurs(const vector<int> &vec, int val);

int main() {
    const int asize = 8;
    int a[asize] = {1, 1, 2, 3, 5, 8, 13, 21};
    int ival = 6;

    vector<int> ivec(a, a + asize);
    list<int> ilist(a, a + asize);

    int *pia = find_out(a, a + asize, 21);
    if (pia != a + asize) cout << "找到了 " << *pia << endl;

    vector<int>::iterator it;
    it = find_out(ivec.begin(), ivec.end(), 21);
    if (it != ivec.end()) cout << "找到了 " << *it << endl;

    list<int>::iterator iter;
    iter = find_out(ilist.begin(), ilist.end(), 21);
    if (iter != ilist.end()) cout << "找到了 " << *iter << endl;
    // insert
    iter = ilist.begin();
    while (iter != ilist.end()) {
        if (*iter >= ival) {
            cout << "正确位置已部署" << endl;
            ilist.insert(iter, ival);
            break;
        }
        iter++;
        if (iter == ilist.end()) ilist.push_back(ival);
    }
    iter = ilist.begin();
    for (; iter != ilist.end(); ++iter) {
        cout << *iter << " ";
    }
    // string insert
    cout << endl << "string insert" << endl;
    string sval = ("Part Two");
    list<string> slist;
    slist.push_back(sval);
    list<string>::iterator istr = find_out(slist.begin(), slist.end(), sval);
    if (istr != slist.end()) cout << "找到了 " << *istr << endl;
    slist.insert(istr, 8, "dummy");
    istr = slist.begin();
    for (; istr != slist.end(); ++istr) {
        cout << *istr << " ";
    }
    // list insert
    cout << endl << "list insert" << endl;
    int ia1[10] = {1, 5, 7, 9, 13, 55, 89, 91, 102, 167};
    int ia2[5] = {18, 25, 33, 40, 44};
    list<int> elems(ia1, ia1 + 9);

    list<int>::iterator itia = find_out(elems.begin(), elems.end(), 55);
    elems.insert(itia, ia2, ia2 + 5);
    itia = elems.begin();
    for (; itia != elems.end(); itia++) {
        cout << *itia << " ";
    }

    //调用泛型filter
    int ia3[7] = {6, 10, 8, 4, 10, 7, 10};
    vector<int> vec(ia3, ia3 + 7);
    cout << endl << "共有 " << count_occurs(vec, 10) << " 个";

    const int elem_size = 8;
    int ia4[elem_size] = {12, 8, 43, 0, 6, 21, 3, 7};
    vector<int> ivec1(ia4, ia4 + elem_size);

    int ia5[elem_size];
    vector<int> ivec2(elem_size);

    cout << "filtering intager array for values less than 8 \n";
    filter(ia4, ia4 + elem_size, ia5, elem_size, less<int>());

    cout << "filtering intager array for values greater than 8 \n";
    filter(ivec1.begin(), ivec1.end(), ivec2.begin(), elem_size, greater<int>());

    // 采用Iterator Inserts 方式
    vector<int> ivec3;
    cout << "filtering values greater than 8 by Iterator Inserts \n";
    filter(ivec1.begin(), ivec1.end(), back_inserter(ivec3), elem_size, greater<int>());

    //使用iostream Iterators
    string word;
    vector<string> text;
    while (cin >> word)
        text.push_back(word);
    sort(text.begin(),text.end());
    for (int i = 0; i < text.size(); ++i) {
        cout << text[i] << " ";
    }

    //
    ifstream in_file("input_file.txt");
    ofstream out_file("output_file.txt");
    if (!in_file || !out_file){
        cerr << "error!"<<endl;
        return -1;
    }

    istream_iterator<string> is(in_file);
    istream_iterator<string> eof;

    vector<string> text;
    copy(is,eof,back_inserter(text));

    sort(text.begin(),text.end());

    ostream_iterator<string> os(out_file," ");
    copy(text.begin(),text.end(),os);

}