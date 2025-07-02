#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int, string>> people(n);
    for (int i = 0; i < n; i++){
        int t;
        string s;
        cin >> t >> s;
        people[i] = make_pair(t, s);
    }
    int toy = 0;
    for (int i = 0; i < m; i++){
        int t,num;
        cin >> t>>num;
        bool flag = false;
        flag = t^people[toy].first;
        if (flag) {
            toy = abs(toy + num) % n;
        } else {
            toy = abs(toy + n -num) % n;
        }
    }
    cout << people[toy].second << endl;
    return 0;
}