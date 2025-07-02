#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    vector<int> a(26, 0);
    for (int i = 0; i < s.size(); i++) {
        a[s[i] - 'a']++;
    }
    if (*max_element(a.begin(), a.end()) > s.size() / 2) {
        cout << "-1" << endl;
        return 0;
    }
    priority_queue<pair<int, char>> q;
    for (int i = 0; i < 26; i++) {
        if (a[i] > 0) {
            q.push({a[i], i + 'a'});
        }
    }
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        auto p = q.top();
        int flag = 0;
        if (!q.empty() && q.top().second == s[i]) {
            q.pop();
            flag = 1;
        }
        if (q.empty()) {
            ans += p.second;
            for (int j = i; j >= 0; j--) {
                if (ans[i] != s[j] && ans[j] != s[i]) {
                    swap(ans[i], ans[j]);
                    cout << ans << endl;
                    return 0;
                }
            }
        }
        auto p2 = q.top();
        q.pop();
        ans += p2.second;
        if (--p2.first > 0)
            q.push(p2);
        if (flag)
            q.push(p);
    }
    cout << ans << endl;
    return 0;
}