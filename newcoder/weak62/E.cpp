#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<pair<int, int>> pa(q);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        pa[i] = {l - 1, r - 1};
    }
    int len = pa[0].second - pa[0].first + 1;
    int mid = len / 2;
    for(int i = 0; i < q; i++) {
        int l = pa[i].first;
        int r = pa[i].second;
        vector<int> ans(a.begin() + l, a.begin() + r + 1);
        nth_element(ans.begin(), ans.begin() + mid, ans.end());
        cout << ans[mid] << endl;
    }

    return 0;
}