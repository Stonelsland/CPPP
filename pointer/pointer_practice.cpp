//
// Created by Phil on 2020/4/11.
//

#include "pointer_practice.h"
int main(){
    int* pi = 0; //定义、初始化一个指向整型变量的指针
    cout << pi << endl; // 我康康地址是啥
    int ival = 1024;
    pi = &ival; //把ival的存储地址存到pi指针中
    cout << pi << endl; //我再康康地址是啥

    cout << "**********************************************************************************************";

    ival = *pi + 1024;
    cout << "Now,'ival' is: " << ival << endl ; //通过对pi提领，操作所指对象
    vector<int> fibonacci, lucas, pell; //定义三个数组，未初始化
    vector<int>*  seq_addrs[ 3 ] = {    //把这三个数组在内存中的地址存在一个指针数组里
            &fibonacci, &lucas, &pell
    };

    const int seq_cnt = 3; //常量，代表参与猜数游戏数组的个数
    vector<int>* current_vec = 0; //定义一个指针，用来接受上面三个数组中随便某一个数组的地址

    // 伪随机数，用来输出随机数
    srand((unsigned) time(NULL)); //srand() 里面给time(NULL)，可使seed每次都随着时间变化
    for (int i = 0 ; i < seq_cnt ; ++i){
        int seq_index = rand() % 3;// 随机给0~2之间的整数给seq_addrs数组的下标
        current_vec = seq_addrs[ seq_index ]; //随机把数组的地址赋值给指针
        cout << current_vec << endl;
    }

    cout << "**********************************************************************************************";

    vector<int>* pv = &fibonacci; // 把数组fibonacci的地址赋值给pv指针，用pv指针去操作这个数组
    // 直接用数组判断自己是否是空的,要用 . 来调用empty()
    // if (fibonacci.empty())
    // 用pv指针判断数组是否是空的，要用 -> 调用empty()，而不能用 .
    // if (pv -> empty())
    return 0;
}