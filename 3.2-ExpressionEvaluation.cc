/*
今天上课，老师教了小易怎么计算加法和乘法，乘法的优先级大于加法，但是如果一个运算加了括号，那么它的优先级是最高的。例如：
1+2*3=7
1*(2+3)=5
1*2*3=6
(1+2)*3=9
现在小易希望你帮他计算给定3个数a，b，c，在它们中间添加"+"， "*"， "("， ")"符号，能够获得的最大值。

输入描述:
一行三个数a，b，c (1 <= a, b, c <= 10)

输出描述:
能够获得的最大值
示例1
输入
1 2 3
输出
9
*/

#include <iostream>
// #include <vector>
// #include <algorithm>

using namespace std;

double max1(double a, double b){
    return max(a + b, a * b);
}

double max2(double a, double b, double c){
    return max(max1(a, b) + c, max1(a, b) * c);
}

int main(){
    double a, b, c;
    while(cin >> a >> b >> c){
        cout << max2(a, b, c) << endl;
    }
    /* 举例子的思路……很挫
    int a, b, c;
    while(cin >> a >> b >> c){
        vector<int> v(6);
        v[0] = a + b + c;
        v[1] = a + b * c;
        v[2] = (a + b) * c;
        v[3] = a * b * c;
        v[4] = a * b + c;
        v[5] = a * (b + c);
        sort(v.begin(), v.end());
        cout << v[5] << endl;
    }
    */
    return 0;
}