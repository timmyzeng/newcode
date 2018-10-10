/*
小易喜欢的单词具有以下特性：
1.单词每个字母都是大写字母
2.单词没有连续相等的字母
3.单词没有形如“xyxy”(这里的x，y指的都是字母，并且可以相同)这样的子序列，子序列可能不连续。
例如：
小易不喜欢"ABBA"，因为这里有两个连续的'B'
小易不喜欢"THETXH"，因为这里包含子序列"THTH"
小易不喜欢"ABACADA"，因为这里包含子序列"AAAA"
小易喜欢"A","ABA"和"ABCBA"这些单词
给你一个单词，你要回答小易是否会喜欢这个单词（只要不是不喜欢，就是喜欢）。 
输入描述:
输入为一个字符串，都由大写字母组成，长度小于100

输出描述:
如果小易喜欢输出"Likes",不喜欢输出"Dislikes"
示例1
输入
AAA
输出
Dislikes
*/
#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    while(cin >> str){
        int arr[256];
        for (int i = 0; i < 256; ++ i){
            arr[i] = 0;
        }

        int size = str.size();
        bool flag = false;
        for(int i = 0; i < size; ++ i){
            if(islower(str[i])){
                cout << "Dislikes" << endl;
                flag = true;
                break;
            }
            if(i+1 <= size && str[i] == str[i+1]){
                cout << "Dislikes" << endl;
                flag = true;
                break;
            }
            ++arr[(int)(str[i])];
        }
        if(flag)
            continue;

        for (int i = 0; i < size; ++ i){
            if(arr[(int)(str[i])] == 1)
                str.erase(i, 1);
        }

        size = str.size();
        for (int i = 0; i < size - 3; ++ i){
            string str1 = str.substr(i, 2);
            for (int j = i + 2; j < size - 1; ++ j){
                string str2 = str.substr(j, 2);
                if(str1 == str2){
                    cout << "Dislikes" << endl;
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag)
            continue;

        cout << "Likes" << endl;
    }
}