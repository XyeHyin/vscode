#include <bits/stdc++.h>
using namespace std;
int main() { 
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int sum = 0;
    for (int i = 1; i < n - 1;i++){
        sum += a[i];
    }
    printf("%.2f\n", sum * 1.0 / (n - 2));
}