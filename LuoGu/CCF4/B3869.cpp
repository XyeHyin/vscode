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
int main(){
    int _;
    cin >> _;
    while(_--){
        int r;
        string s;
        cin >> r >> s;
        cout << toDecimal(s, r) << endl;
    }

    return 0;
}