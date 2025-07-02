#include <bits/stdc++.h>
#define endl '\n'

int a[8][8][8], b[8][8];
bool f[8];

int main() {
    int n, m, q;
    std::string s;
    std::cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        std::cin >> s;
        for (int j = 1; j <= m; j++) {
            b[i][j] = s[j] - '0';
        }
    }

    for (int k = 1; k <= q; k++) {
        for (int i = 1; i <= n; i++) {
            std::cin >> s;
            for (int j = 1; j <= m; j++) {
                a[k][i][j] = s[j] - '0';
                if (a[k][i][j] && b[i][j]) {
                    f[k] = true;
                }
            }
        }
    }
    int ans = q + 1, mm;
    std::vector<int> re;
    for (int k = (1 << q) - 1; k; k--) {
        mm = 0;
        std::vector<std::vector<int>> aa(n + 1, std::vector<int>(m + 1, 0));
        // std:: cout << -1;
        for (int p = 0; p < q; p++) {

            // std:: cout << n << ' ' << m;
            if ((1 << p) & k) {
                mm++;
                if (f[p + 1]) goto A;
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= m; j++) {
                        if (a[p + 1][i][j]) {
                            aa[i][j] = 1;
                        }
                    }
                }
            }
        }
        // std:: cout << -1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (aa[i][j] + b[i][j] == 0) {
                    goto A;
                }
            }
        }
        // std:: cout << mm;
        if (ans >= mm) {
            re.clear();
            ans = mm;
            for (int p = 0; p < q; p++) {
                if ((1 << p) & k) {
                    re.push_back(p + 1);
                }
            }
        }
    A:;
    }

    if (ans <= q && ans) {
        std::cout << ans << endl;
        for (int i = 0; i < ans; i++) {
            std::cout << re[i] << ' ';
        }
    } else {
        std::cout << -1;
    }

    return 0;
}