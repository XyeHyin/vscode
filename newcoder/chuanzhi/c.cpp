#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int sum = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        q.push(x);
        sum += x;
    }
    sum = (sum + k) / n;
    cout << sum << endl;
    k += m;
    int flag=0;
    int ans = 0;
    while (!q.empty()&&k){
        int tp = q.top();
        q.pop();
        if(tp<q.top()){
            if(k-q.top()<0)q.push(k + tp);
            else{
                q.push(q.top());
            }
            k-=q.top();
        }else{
            int j = 2;
            q.pop();
            while(!q.empty()&&q.top()==tp){
                q.pop();
                j++;
            }


        }
    }
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
