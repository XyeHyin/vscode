#include <bits/stdc++.h>
using namespace std;
string tobin(long long N) {
    if (N == 0) return "0";
    string s = "";
    while (N) {
        s += to_string(N % 2);
        N /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        cout << tobin(num) << " ";
    }
    return 0;
}