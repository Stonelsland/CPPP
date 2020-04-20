###### 2020 04 14

#### 泛型指针

每个标准容器都有

`begin()`[返回一个iterator，指向第一个元素],

`end()`[返回一个iterator，指向最后一个元素的下一位置]

`vector<string>::iterator iter = svec.begin`:

此处iter被定义为一个iterator，指向一个vector，后者的元素类型为string，其初始值指向svec的第一个元素(双冒号[::]表示此iterator是位于string vector定义内的嵌套类型)

list不支持iterator的偏移运算

<img src="../lafamu.jpg">