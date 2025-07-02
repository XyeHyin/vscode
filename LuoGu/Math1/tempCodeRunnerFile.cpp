#include <bits/stdc++.h>
using namespace std;
string Decimalto(int n, int radix) {
    if (n == 0)
        return "0";
    string res = "";
    while (n != 0) {
        int num = n % radix;
        n /= radix;
        if (num < 0) {
            num += (-radix);
            n += 1;
        }
        if (num >= 10) {
            res += (char)(num - 10 + 'A');
        } else {
            res += to_string(num);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}
int main() {
    int n, radix;
    cin >> n >> radix;
    string ans = Decimalto(n, radix);
    cout << n << "=" << ans << "(base" << radix << ")" << endl;
    return 0;
}