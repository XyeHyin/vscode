#include <bits/stdc++.h>
using namespace std;
#define ll long long
string dictionary = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string Decimalto(ll N, int radix) {
    string s = "";
    while (N) {
        s += dictionary[N % radix];
        N /= radix;
    }
    reverse(s.begin(), s.end());
    return s;
}
int main(){
    int n, m;
    cin >> n >> m;
    cout<<Decimalto(n, m)<<endl;
    return 0;
}