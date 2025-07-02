#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int cnt = 0;
    for (int i = 1; i <= n;) {
        if (a[i]) {
            for (int j = i; j <= n; j++) {
                if (!a[j]) break;
                a[j]--;
                if(j==n) break;
            }
            cnt++;
        }else{
            i++;
        }
    }
    cout << cnt;
    return 0;
}