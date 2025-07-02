#include <bits/stdc++.h>
using namespace std;
int main() {
    string a;
    cin >> a;
    vector<char> b(26, 0);
    for (int i = 0; i < 3; i++) {
        b[a[i] - 'a']++;
    }
    int temp = max_element(b.begin(), b.end()) - b.begin();
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        if (a[i] - 'a' != temp) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}