/*
请设计一个高效的方法，找出任意指定单词在一篇文章中的出现频数。
给定一个string数组article和数组大小n及一个待统计单词word，
请返回该单词在文章中的出现频数。保证文章的词数小于等于1000。
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Frequency {
public:
    int getFrequency(vector<string> article, int n, string word) {
        // 利用algorithm中的count进行统计
        return count(article.begin(), article.end(), word);

        // 遍历统计
        // if(article.empty())
        //     return 0;
        // int count = 0;
        // for(int i = 0; i < n; ++ i){
        //     if(article[i] == word){
        //         ++ count;
        //     }
        // }
        // return count;
    }
};
