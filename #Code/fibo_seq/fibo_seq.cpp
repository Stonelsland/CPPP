//
// Created by NOAH on 2020/4/11.
//

#include "fibo_seq.h"

bool fibo_elem(int, int &);
const vector<int>* fibo_seq(int size);
int main() {
    int pos;
    cout << "please enter a position:";
    cin >> pos;

    int elem;
    if (fibo_elem(pos, elem)) {
        const vector<int> *pseq = fibo_seq(pos);
        for (int i = 0; i < pos ; ++i) {
            cout << (*pseq)[i] << ' ';
        }
    } else {
        cout << "sorry";
    }
}