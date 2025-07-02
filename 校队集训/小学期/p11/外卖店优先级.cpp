#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> a(n + 1, 0);
    vector<pair<int, int>> b(m+1);
    for (int i = 1; i <= m; i++) {
        cin >> b[i].first >> b[i].second;
    }
    sort(b.begin(), b.end(),
         [](pair<int, int> x, pair<int, int> y) { return x.first < y.first; });
    int time = 0;
    set<int> q;
    vector<bool> flag(n, false);
    for (int i = 1; i <= m; i++) {
        // cout<<a[1]<<" "<<a[2]<<endl;
        // cout << time << endl;
        if (b[i].first == time) {
            // cout << b[i].second << " " << a[b[i].second] << endl;
            a[b[i].second] += 2;
            flag[b[i].second] = true;
            if (a[b[i].second] > 5&&!q.count(b[i].second)) {
                q.insert(b[i].second);
            }
        }
        if(i==m){
            for (int j = 1; j <= n; j++) {
                if (!flag[j] && a[j] > 0) {
                    a[j]--;
                    if(a[j]<=3&&q.count(j)){
                        q.erase(j);
                    }
                }
            }
        }
        if (b[i].first > time) {
            time++;
            for (int j = 1; j <= n; j++) {
                if (!flag[j] && a[j] > 0) {
                    a[j]--;
                    if(a[j]<=3&&q.count(j)){
                        q.erase(j);
                    }
                }
                flag[j] = false;
            }
            i--;
        }
       
    }
    cout << q.size()<< endl;
    return 0;
}