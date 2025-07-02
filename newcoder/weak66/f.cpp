#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    while (n--) {
        int nn, k;
        cin >> nn >> k;
        string s;
        cin >> s;
        vector<string> v;
        for (int i = 0; i < s.size(); i++) {
            string tmp = s.substr(i,1) + s.substr(0, i) + s.substr(i + 1);
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());
        cout << v[k-1] << endl;

    }
    return 0;
}