#include <bits/stdc++.h>
using namespace std;
#define ll long long
string dictionary = "0123456789ABCDEF";
ll toDecimal(string N, int radix) {
    ll sum = 0;
    ll base = 1;
    for (int i = N.size() - 1; i >= 0; i--) {
        sum += base * dictionary.find(N[i]);
        base *= radix;
    }
    return sum;
}
string Decimalto(ll N, int radix) {
    string s = "";
    while (N) {
        s += dictionary[N % radix];
        N /= radix;
    }
    reverse(s.begin(), s.end());
    return s;
}
int main() {
    int n, ton;
    string N;
    cin >> n >> N >> ton;
    ll num = toDecimal(N, n);
    cout << Decimalto(num, ton) << endl;
    return 0;
}