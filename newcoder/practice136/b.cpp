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
        int n;
        cin >> n;
        int cnt = 0;
        deque<int> a;
        deque<int> b;
        for(int i = 1; i <= n; i++) {
            if (i % 3 == 0 || i % 37 == 0) {
                cnt++;
                a.push_front(i);
            }
            else {
                b.push_back(i);
            }
        }
        if(cnt < (n + 2) / 3) {
            cout << "Baka!";
            return;
        }
        while(!a.empty()&&!b.empty()) {
            if(!b.empty()) {
                cout << b.front() << " ";
                b.pop_front();
            }
            if(!a.empty()) {
                cout << a.back() << " ";
                a.pop_back();
            }
            if(!b.empty()) {
                cout << b.front() << " ";
                b.pop_front();
            }
        }
        while(!a.empty()) {
            cout << a.back() << " ";
            a.pop_back();
        }
        while(!b.empty()) {
            cout << b.front() << " ";
            b.pop_front();
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