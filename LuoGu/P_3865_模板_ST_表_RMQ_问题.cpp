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
template <typename T> class SparseTable {
    using VT = vector<T>;
    using VVT = vector<VT>;
    using func_type = function<T(const T &, const T &)>;

    VVT ST;

    static T default_func(const T &t1, const T &t2) { return max(t1, t2); }

    func_type op;

  public:
    SparseTable(const vector<T> &v, func_type _func = default_func) {
        op = _func;
        int len = v.size(), l1 = ceil(log2(len)) + 1;
        ST.assign(len, VT(l1, 0));
        for (int i = 0; i < len; ++i) {
            ST[i][0] = v[i];
        }
        for (int j = 1; j < l1; ++j) {
            int pj = (1 << (j - 1));
            for (int i = 0; i + pj < len; ++i) {
                ST[i][j] = op(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query(int l, int r) {
        int lt = r - l + 1;
        int q = floor(log2(lt));
        return op(ST[l][q], ST[r - (1 << q) + 1][q]);
    }
};
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    SparseTable<int> st(a);
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r) << endl;
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