//
// Created by NOAH on 2020/4/14.
//

#include "iterator_demo.h"
int count_occurs(const vector<int> &vec,int val);
int main() {
    const int asize = 8;
    int a[asize] = {1, 1, 2, 3, 5, 8, 13, 21};
    int ival = 6;

    vector<int> ivec(a, a + asize);
    list<int> ilist(a, a + asize);

    int *pia = find(a, a + asize, 21);
    if (pia != a + asize) cout << "找到了 " << *pia << endl;

    vector<int>::iterator it;
    it = find(ivec.begin(), ivec.end(), 21);
    if (it != ivec.end()) cout << "找到了 " << *it << endl;

    list<int>::iterator iter;
    iter = find(ilist.begin(), ilist.end(), 21);
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
    list<string>::iterator istr = find(slist.begin(), slist.end(), sval);
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

    list<int>::iterator itia = find(elems.begin(), elems.end(), 55);
    elems.insert(itia, ia2, ia2 + 5);
    itia = elems.begin();
    for (; itia != elems.end(); itia++) {
        cout << *itia << " ";
    }

    //
    int ia3[7] = {6,10,8,4,10,7,10};
    vector<int> vec(ia3,ia3+7);
    cout << endl << "共有 " <<count_occurs(vec,10)<<" 个";
}