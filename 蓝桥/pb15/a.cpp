#include <bits/stdc++.h>
using namespace std;
string Decimalto(int n,int b) {
    string ans;
    while (n) {
        ans += n % b + '0';
        n /= b;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
bool ok(int n) {
    string n4 = Decimalto(n, 4);
    string n2 = Decimalto(n, 2);
    int cnt2=count(n2.begin(), n2.end(), '1');
    int cnt4 = 0;
    for(int i=0;i<n4.size();i++){
        cnt4+=n4[i]-'0';
    }
    return cnt2 == cnt4;
}
int main() {
    int cnt = 0;
    for (int i = 1; i <= 2024;i++){
        if (ok(i)) {
            cnt++;
        }
    }
        cout << cnt;
    return 0;
}