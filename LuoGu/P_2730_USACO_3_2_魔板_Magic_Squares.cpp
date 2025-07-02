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
void solve(){
    string s = "";
    for (int i = 0; i < 8; i++) {
        int x;
        cin >> x;
        s += to_string(x);
    }
    string ss="12345678";
    map<string, string> mp;
    queue<string> q;
    q.push(ss);
    mp[ss] = "";
    while(!q.empty()){
        string now = q.front();
        q.pop();

        string sa = now;
        swap(sa[0], sa[7]);
        swap(sa[1], sa[6]);
        swap(sa[2], sa[5]);
        swap(sa[3], sa[4]);
        if(!mp.count(sa)){
            mp[sa] = mp[now] + "A";
            q.push(sa);
        }

        string sb = now;
        swap(sb[2],sb[3]);
        swap(sb[1],sb[2]);
        swap(sb[0],sb[1]);
        swap(sb[4],sb[5]);
        swap(sb[5],sb[6]);
        swap(sb[6],sb[7]);
        if(!mp.count(sb)){
            mp[sb] = mp[now] + "B";
            q.push(sb);
        }

        string sc = now;
        sc[1] = now[6];
        sc[2] = now[1];
        sc[5] = now[2];
        sc[6] = now[5];
        if(!mp.count(sc)){
            mp[sc] = mp[now] + "C";
            q.push(sc);
        }

        if(mp.count(s)){
            cout << mp[s].size() << endl;
            cout << mp[s] << endl;
            return;
        }
    }
    return;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)	solve();
    return 0;
}