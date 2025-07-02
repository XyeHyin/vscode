#include <bits/stdc++.h>
using namespace std;

int main() {
   int n = 100000;
   long long sum = 0;
   long long sum1 = 0;
   for (int i = 0; i < n; i++) {
       int a;  
       cin >> a;
       sum += a;
       sum1 += a * a;
    }
    long long S = (sum * sum - sum1) / 2;
    cout << S << endl;

    return 0;
}