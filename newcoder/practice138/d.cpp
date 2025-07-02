#include <bits/stdc++.h>
using namespace std;

#define int  unsigned long long
#define double long double
#define PII pair<int, int>
#define dbg(x) std::cout << #x << ":" << x << " "
#define MP make_pair
#define PB push_back
#define rep(i, x, n) for (int i = x; i <= n; i++)
#define dep(i, x, n) for (int i = x; i >= n; i--)
#define arrout(a, n) rep(i, 1, n) std::cout << a[i]
#define arrin(a, n) rep(i, 1, n) std::cin >> a[i]
#define endl '\n'
string decimalToBinary(int n) {
    string s;
    while (n) {
        s += (n % 2) + '0';
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}
int binaryToDecimal(string s) {
    int n = 0;
    for (int i = 0; i < s.size(); i++) {
        n = n * 2 + (s[i] - '0');
    }
    return n;
}
void solve() {
    int n;
    cin >> n;
    vector<int> dic(17);
    for(int i = 1; i <= 16; i++) {
        dic[i] = (1ULL << i)-1;
    }
    int maxx = 720720;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int len = s.size();
        int tmp = binaryToDecimal(s);
        dic[len] &= tmp;
    }
    vector<string> dicc(17);
    for (int i = 1; i <= 16; i++) {
        dicc[i] = decimalToBinary(dic[i]);
        while(dicc[i].size() < i) {
            dicc[i] = '0' + dicc[i];
        }
        cout<<dicc[i]<<endl;
    }
    vector<string> a(maxx + 1);
    for (int i = 1;i <= 16; i++) {
        int len = dicc[i].size();
        for (int j = 0; j < maxx; j++) {
            a[j] += dicc[i][j % len];
        }
    }
    for (int i = 0; i < maxx; i++) {
        string s = a[i];
        if(*min_element(s.begin(), s.end()) == '1') {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}