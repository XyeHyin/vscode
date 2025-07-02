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
        int q;
        cin >> q;
        unordered_map<int, int> mp;
        while(q--){
            int op;
            cin >> op;
            if(op == 1){
                int x;
                cin >> x;
                mp[x]++;
            }else if(op == 2){
                int x;
                cin >> x;
                mp[x]--;
                if(mp[x] == 0){
                    mp.erase(x);
                }
            }else{
                cout<<mp.size() << endl;
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