#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    int avg = sum / n;
    int ans = 0;
    if(a[0] != avg){
        a[1]-=avg-a[0];
        a[0] = avg;
        ans++;
    }
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] != avg) {
            a[i + 1] -= avg - a[i];
            a[i] = avg;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}