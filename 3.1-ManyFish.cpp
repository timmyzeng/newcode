/*
牛牛有一个鱼缸。鱼缸里面已经有n条鱼，每条鱼的大小为fishSize[i] (1 ≤ i ≤ n,均为正整数)，
牛牛现在想把新捕捉的鱼放入鱼缸。鱼缸内存在着大鱼吃小鱼的定律。
经过观察，牛牛发现一条鱼A的大小为另外一条鱼B大小的2倍到10倍(包括2倍大小和10倍大小)，
鱼A会吃掉鱼B。考虑到这个，牛牛要放入的鱼就需要保证：
1、放进去的鱼是安全的，不会被其他鱼吃掉
2、这条鱼放进去也不能吃掉其他鱼
鱼缸里面已经存在的鱼已经相处了很久，不考虑他们互相捕食。
放入的新鱼之间也不会相互捕食。现在知道新放入鱼的大小范围[minSize,maxSize](考虑鱼的大小都是整数表示),
牛牛想知道有多少种大小的鱼可以放入这个鱼缸。 

输入描述:
输入数据包括3行. 第一行为新放入鱼的尺寸范围minSize,maxSize(1 ≤ minSize,maxSize ≤ 1000)，以空格分隔。
第二行为鱼缸里面已经有鱼的数量n(1 ≤ n ≤ 50)
第三行为已经有的鱼的大小fishSize[i](1 ≤ fishSize[i] ≤ 1000)，以空格分隔。

输出描述:
输出有多少种大小的鱼可以放入这个鱼缸。考虑鱼的大小都是整数表示
示例1
输入
1 12
1
1
输出
3
*/
#include <iostream>

using namespace std;

int core(int arr[], int n, int min, int max){
    int count = 0;
    for (int i = min; i <= max; ++i){
        bool flag = false;
        for (int j = 0; j < n; ++ j){
            if((2*i <= arr[j] && arr[j] <= 10*i) || (2*arr[j] <= i && i <= 10*arr[j]) ){
                flag = true;
                break;
            }
        }
        if(!flag)
            count++;
    }
    return count;
}

int main(){
    int minSize, maxSize;
    while(cin >> minSize >> maxSize){
        int n;
        cin >> n;
        int fishSize[n];
        for (int i = 0; i < n; ++ i){
            int tmp;
            cin >> tmp;
            fishSize[i] = tmp;
        }
        cout << core(fishSize, n, minSize, maxSize) << endl;
    }
    return 0;
}
