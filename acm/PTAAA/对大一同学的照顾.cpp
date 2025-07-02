#include <bits/stdc++.h>
using namespace std;
#define dbg(x) std::cout << #x << ":" << x << " "
int main() {
    int m, n, k;
    cin >> m >> n >> k;
    while (k--) {
        stack<int> st;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int cur = 1;
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            while (st.empty() ||  (st.top() != a[i] && st.size() < m && cur <= n)) st.push(cur++);
            if (st.top() == a[i])  st.pop();
            else {
                ok = 0;
                break;
            }
        }
    
    if (!ok)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    }
}
