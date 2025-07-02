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
    int n,m, k;
    cin >> n >> m >> k;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)  {
        int a;
        cin >> a;
        pq.push(a);
    }
    int ans = 0;

    while((!pq.empty()) && (m > 0 || k > 0)){
        int num = pq.top();
        pq.pop();
        if (num == 0) {
            continue;
        }
        if (num % 2 == 0 && m > 0) {
            num /= 2;
            m--;
        } else if (num % 2 == 1 && k > 0) {
            num ^= 1;
            k--;
        }else{
            ans += num;
            continue;
        }
        pq.push(num);
    }
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;
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