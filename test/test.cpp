//
// Created by Phil on 2020/4/11.
//

#include "test.h"
int main(){
    srand(5);
    for (int i = 0; i < 15; ++i){
        int j = rand() % 6;
        cout << j << '\n';
    }

    return 0;
}