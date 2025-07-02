    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    string dictionary = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    ll toDecimal(string N, int radix) {
        ll sum = 0;
        ll base = 1;
        for (int i = N.size() - 1; i >= 0; i--) {
            sum += base * dictionary.find(N[i]);
            base *= radix;
        }
        return sum;
    }
    int main() {
        int n;
        string s;
        cin>>n>>s;
        cout<<toDecimal(s, n)<<endl;
        return 0;
    }