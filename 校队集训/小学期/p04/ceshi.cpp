#include <bits/stdc++.h>
using namespace std;
int  a[10], ans;
void dfs(int t, int cur) {
    if (!a[1] && !a[2] && !a[3]) {
        ans++;
        return;
    }
    for (int i = 1; i <= 3; i++) {
        if (i == cur) continue;
        for (int j = t; j <= a[i]; j++) {
            a[i] -= j;
            dfs(j + 1, i);
            a[i] += j;
        }
    }
    return;
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        ans = 0;
        cin>>a[1]>>a[2]>>a[3];
        dfs(1, 0);
        cout<<ans<<endl;
    }
    return 0;
}