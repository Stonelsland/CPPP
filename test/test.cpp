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

    cout << "************************\n"; // 分割线

    int* pi1 = NULL;
    cout << pi1 << endl; //输出0

    int* pi2 = 0;
    cout << pi2 << endl; //输出0

    int* pi3;
    cout << pi3 << endl; //输出随机地址

    cout << "array和vector数组定义及初始化：";
    int seq_size = 6;
    int pell_seq[seq_size] = {1,1,2,3,5,8,}; // array数组定义及初始化
    vector<int> elem_seq(6); //vector数组的第一种定义方法方法，但初始化只能每个元素挨个赋值，如，elem_seq[ 0 ] = 1
    vector<int> elem_seq_cpy(pell_seq,pell_seq + 6); //vector数组的第二种初始化方法，直接把已经初始化好的array数组加到这里
    /*
     * 1.5节主要写了array和vector数组的定义、初始化方式
     * array: int pell_seq[ 6 ] = {};  要給数据类型、数组名称、数组长度；初始化时如果大括号内有数据，可以不写数组长度
     * vector：vector<int> elem_seq(6); 要给vector<**> 尖括号内给数据类型，后面小括号给数组长度
     * vector<int> elem_seq(pell_seq, pell_seq + 6) 初始化方法的一种，另一种是用索引下标的方式把每个数组元素填满
     */
    return 0;
}