#include <bits/stdc++.h>
using namespace std;
int main() {
    int m, n;
    cin >> m >> n;
    vector<int> a(m + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    vector<int> v;
    int j = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        while(j<b[i]) {
            v.push_back(a[++j]);
        }
        sort(v.begin(), v.end());
        cout << v[cnt]<<endl;
        cnt++;
    }
    return 0;
}