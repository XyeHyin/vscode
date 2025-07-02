#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define PII pair<int, int>
#define dbg(x) std::cout << #x << ":" << x << " "
#define MP make_pair
#define PB push_back
#define rep(i,x,n) for(int i=x;i<=n;i++)
#define dep(i,x,n) for(int i=x;i>=n;i--)
#define arrout(a,n) rep(i,1,n)std::cout<<a[i]
#define arrin(a,n) rep(i,1,n)std::cin>>a[i]
#define endl '\n'
string dictionary = "0123456789abcdefghijklmnopqrstuvwxyz";
string dic = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int toDecimal(string N, int radix) {
    int sum = 0;
    int base = 1;
    for (int i = N.size() - 1; i >= 0; i--) {
        sum += base * dictionary.find(N[i]);
        base *= radix;
    }
    return sum;
}
int toDecimal2(string N, int radix) {
    int sum = 0;
    int base = 1;
    for (int i = N.size() - 1; i >= 0; i--) {
        sum += base * dic.find(N[i]);
        base *= radix;
    }
    return sum;
}
string DecimaltoBinary(int n) {
    string s = "";
    while (n) {
        s += dictionary[n % 2];
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}
string base32 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ23456789";
void solve(){
    int n;
    cin >> n;
    getchar();
    string s;
    int j = 0;
    vector<pair<int,string>> mp;
    while(n--){
        getline(cin, s);
        stringstream ss(s);
        string sss;
        vector<string> a;
        while(ss>>sss){
            a.push_back(sss);
        }
        if(a[0]=="Join"){
            int shi = toDecimal(a[1], 16);
            mp.push_back(make_pair(shi, a[2]));
            dbg(shi) << endl;
        }
        if(a[0]=="Download"){
            string before = "";
            for (int i = a[1].size() - 1; i >= a[1].size() - 4;i--){
                before = a[1][i] + before;
            }
            string after = "";
            for (int i = 0; i < before.size();i++){
                int tmp = base32.find(before[i]);
                string bin = DecimaltoBinary(tmp);
                if(before[i]=='A') bin = "00000";
                while(bin.size()%5!=0){
                    bin = '0' + bin;
                }
                after += bin;
            }
            int af = toDecimal2(after, 2);
            dbg(af);
            int minn=0x3f3f3f3f,pos=0;
            for (int i = 0; i < mp.size();i++){
                 if((af^mp[i].first)<minn) {
                     minn = af ^ mp[i].first;
                     pos = i;
                 } else if ((af ^ mp[i].first) == minn){
                    if(mp[i].second<mp[pos].second){
                        pos = i;
                    }
                 }
            }
            // dbg(pos) << endl;
            cout << mp[pos].second << endl;
        }
    }
    
    return;
}

signed main(){
    int t = 1;
    // cin >> t;
    while(t--)	solve();
    return 0;
}