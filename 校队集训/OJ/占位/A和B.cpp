/* 题目描述
有两个正整数A和B，A小于B。已知A和B的和X，以及A和B的最小公倍数Y，问A和B是多少？
输入
一个正整数N（N小于50），表示后面有N组数据，接下来的N行，每行两个整数X和Y（0<X,Y<1e9)
输出
输出N行，每行输出与输入相应的A和B，使用空格分隔。
样例输入
2
10 12
8 15
样例输出
4 6
3 5 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=1;
    // cin >> n;
    while(n--){
        int x, y;
        cin >> x >> y;
        for (int i = 1; i < x;i++){
            // if(lcm(i,x-i)==y){
            //     cout << i << " " << x - i << endl;
            //     break;
            // }
            if(i*(x-i)==y){
                cout << i << " " << x - i << endl;
            }
        }
    }
    return 0;
}