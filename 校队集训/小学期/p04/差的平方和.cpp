#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> mp(200);
vector<int> c;
vector<int> num(100000);
int sum = 0;
void f(int begin, int n) {
    if (c.size() == 2) {
        sum += mp[abs(num[c[0]] - num[c[1]])];
        return;
    }
    for (int i = begin; i < n; i++) {
        c.push_back(i);
        f(i + 1, n);
        c.pop_back();
    }
}
signed main() {
    int n;
    cin >> n;
    for (int i = 0; i <= 200;i++){
        mp[i] = i * i;
    }
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }

    f(0, n);
    cout << sum << endl;
    return 0;
}
