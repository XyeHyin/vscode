#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n;
ll m;
int a[200005];
void solv() {
    freopen("data1.in", "r", stdin);
    freopen("cc.out", "w", stdout);
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        int j;
        for (j = i; j < n && s[j] == s[i]; j++);
        if (j == n || s[i] > s[j]) {
            for (int k = i; k < j; k++)
                cout << s[k];
            i = j - 1;
            continue;
        }
        j--;
        sort(a + i, a + j + 1);
        for (int k = i; k <= j; k++) {
            if (a[k] <= m) {
                m -= a[k];
                cout << s[i];
            }
            cout << s[k];
        }
        i = j;
    }
    cout << '\n';
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--)
        solv();
    return 0;
}