/* 分子和分母的最大公约数为1的分数，被称为既约分数。例如，8 / 1、8 / 3、3 /
    8等等，都是既约分数，请问分子和分母都在 [1, 2024] 之间的既约分数有几个？ */
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    while (b ^= a ^= b ^= a %= b);
    return a;
}
int main() {
    int count = 0;
    for (int i = 1; i <= 2024; i++) {
        for (int j = i; j <= 2024; j++) {
            if (gcd(i, j) == 1&&i!=j) {
                count+=2;
            }else if(gcd(i,j)==1&&i==j){
                count++;
        }
    }
    }
    cout<<count<<endl;
    return 0;
}