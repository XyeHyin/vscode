    #include <bits/stdc++.h>
    using namespace std;
    map<int, vector<int>> mp;
    int f(int x) {
    int maxn = 0;
        for (int i = 0; i < mp[x].size(); i++) {
            maxn = max(maxn, f(mp[x][i]));
        }
        return maxn + mp[x].size();
    }
    int main() {
        int n;
        cin >> n;
        if(n==1){
            cout<<0;
            return 0;
        }
        for (int i = 2; i <= n; i++) {
            int x;
            cin >> x;
            mp[x].push_back(i);
        }
        cout<<f(1)<<endl;
        return 0;
    }