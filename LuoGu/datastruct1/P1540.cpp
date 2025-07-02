#include <bits/stdc++.h>
using namespace std;
int main(){
    int m, n;
    cin >> m >> n;
    deque<int> q;
    int cnt = 0;
    vector<bool> vis(1001, 0);
    for (int i = 0; i <n; i++) {
        int tmp;
        cin >> tmp;
        if(vis[tmp]) continue;
        q.push_back(tmp);
        if(q.size()>m){
            vis[q.front()] = 0;
            q.pop_front();
        }
        if(!vis[tmp]){
            vis[tmp] = 1;
            cnt++;   
        }
    }
    cout << cnt;
    return 0;
}