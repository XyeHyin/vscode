#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a;
    cin >> n;
    vector<int> price(n);
    for (int i = 0; i < n; i++){
        cin >> price[i];
    }
    int minprice = 0x3f3f3f3f;
    int maxprofit = 0;
    for (int i = 0; i < n; i++){
        if (price[i] < minprice)  minprice = price[i];
        else if (price[i] - minprice > maxprofit) maxprofit = price[i] - minprice;
    }
    cout << maxprofit << endl;
}