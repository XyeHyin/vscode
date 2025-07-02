#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    char mp[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mp[i][j];
        }
    } 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j < m - 3) {
                if (mp[i][j] == 'r' && mp[i][j + 1] == 'r' &&
                    mp[i][j + 2] == 'r' && mp[i][j + 3] == 'r') {
                    cout << "kou" << endl;
                    return 0;
                }
            }
            if (i < n - 3 && j < m - 3) {
                if (mp[i][j] == 'r' && mp[i + 1][j + 1] == 'r' &&
                    mp[i + 2][j + 2] == 'r' && mp[i + 3][j + 3] == 'r') {
                    cout << "kou" << endl;
                    return 0;
                }
            }
            if (i < n - 3) {
                if (mp[i][j] == 'r' && mp[i + 1][j] == 'r' &&
                    mp[i + 2][j] == 'r' && mp[i + 3][j] == 'r') {
                    cout << "kou" << endl;
                    return 0;
                }
            }
            if (j < m - 3) {
                if (mp[i][j] == 'p' && mp[i][j + 1] == 'p' &&
                    mp[i][j + 2] == 'p' && mp[i][j + 3] == 'p') {
                    cout << "yukari" << endl;
                    return 0;
                }
            }
            if (i < n - 3 && j < m - 3) {
                if (mp[i][j] == 'p' && mp[i + 1][j + 1] == 'p' &&
                    mp[i + 2][j + 2] == 'p' && mp[i + 3][j + 3] == 'p') {
                    cout << "yukari" << endl;
                    return 0;
                }
            }
            if (i < n - 3) {
                if (mp[i][j] == 'p' && mp[i + 1][j] == 'p' &&
                    mp[i + 2][j] == 'p' && mp[i + 3][j] == 'p') {
                    cout << "yukari" << endl;
                    return 0;
                }
            }

            if (j >= 3 && i < n - 3) {
                if (mp[i][j] == 'r' && mp[i + 1][j - 1] == 'r' &&
                    mp[i + 2][j - 2] == 'r' && mp[i + 3][j - 3] == 'r') {
                    cout << "kou" << endl;
                    return 0;
                }
                if (mp[i][j] == 'p' && mp[i + 1][j - 1] == 'p' &&
                    mp[i + 2][j - 2] == 'p' && mp[i + 3][j - 3] == 'p') {
                    cout << "yukari" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "to be continued" << endl;
    return 0;
}