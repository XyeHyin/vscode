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

int n, tot;
vector<int> nums, sq, res;
bool ok = 0;

void dfs(int i, int cnt, int sum, int flg, int k) {
    if (ok) return;
    if (cnt == k) {
        if (sum == flg) ok = true;
        return;
    }
    if (i >= tot) return;
    if (tot - i < k - cnt) return;
    dfs(i + 1, cnt + 1, sum + sq[i], flg, k);
    if (ok) {
        res.push_back(nums[i]);
        return;
    }
    dfs(i + 1, cnt, sum, flg, k);
}

void solve() {
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    vector<int> all;
    do {
        int num = 0;
        for (auto d : v) num = num * 10 + d;
        all.push_back(num);
    } while (next_permutation(v.begin(), v.end()));
    tot = all.size();
    int tmp = 0;
    for (auto i : all) tmp += i * i;
    int flg = tmp / 2;
    nums = all;
    for (auto i : nums) sq.push_back(i*i);
    int k = tot / 2;
    dfs(0, 0, 0, flg, k);
    if (ok) {
        reverse(res.begin(), res.end());
        for (auto x : res)  cout << x << endl;
    }
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