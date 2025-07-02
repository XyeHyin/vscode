#include <bits/stdc++.h>
using namespace std;
int main() {
    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n;
    cin >> n;
    string ans = "";
    while (n) {
        n--;
        ans += s[n % 26];
        n /= 26;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}