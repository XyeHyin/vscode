#include <bits/stdc++.h>
using namespace std;
int main()
{
    int A, B, D, sum;
    vector<int> yushu;
    cin >> A >> B >> D;
    sum = A + B;
    if(sum==0){
        cout << "0";
        return 0;
    }
    while (sum != 0)
    {
        yushu.push_back(sum % D);
        sum /= D;
    }
    for (int i = yushu.size() - 1; i >= 0;i--){
        cout << yushu[i];
    }
}