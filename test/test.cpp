//
// Created by Phil on 2020/4/11.
//

#include "test.h"
int main(){
    srand(5); //seed不同，每次输出的随机数就不同
    for (int i = 0; i < 15; ++i){
        int j = rand() % 6; // rand()用来限制输出随机数的范围，变换seed，就变换一组随机数
        cout << j << '\n';
    }

    return 0;
}