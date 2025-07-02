#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < min(n - i, m - j); k++)
                cnt += a[i + k][j + k] == a[i][j];
            for (int k = 0; k < min(n - i, j + 1); k++)
                cnt += a[i + k][j - k] == a[i][j];
        }
    }
cout << cnt<< endl;
return 0;
}