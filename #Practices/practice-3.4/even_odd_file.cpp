//
// Created by NOAH on 2020/4/22.
//

#include "even_odd_file.h"

int main() {

    vector<int> input;

    cout << "enter: " << endl;
    istream_iterator<int> in(cin), eos;

    copy(in, eos, back_inserter(input));


    /*
     *  partition(beg，end，unaryPred)
     *  beg为起始位置 end为结束位置 unaryPred为判断条件
     *  partition会将满足unaryPred条件的元素放在序列的开始，不满足条件的放在序列的最后
     *  返回值为一个迭代器，指向满足unaryPred条件的最后一个元素
     *  #若要保持原容器中的元素顺序，则需采用stable_partition()
     *  pred：谓词predicate的简写
        泛型算法的模板参数，某些用Pred来命名，
        表示接纳一个“函数指针”或“函数对象”类型，
        其作用是计算并判断某些参数对象的是非条件
     */
    vector<int>::iterator division =
            stable_partition(input.begin(), input.end(), even_odd_file());

    ofstream even_file("../even.txt"),
            odd_file("../odd.txt");

    if (!even_file || !odd_file) {
        cerr << "open file error";
        return -1;
    }

    ostream_iterator<int> even_iter(even_file, "\n"),
            odd_iter(odd_file, " ");

    copy(input.begin(), division, even_iter);
    copy(division, input.end(), odd_iter);
}
