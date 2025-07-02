#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> last(m, 0);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < m; i++) pq.push(a[i]);
    for (int i = m; i < n; i++){
        int p = pq.top();
        pq.pop();
        if (p < last[p % m]){
            cout << "Karashi lovelove" << endl;
            return 0;
        }
        last[p% m] = p;
        pq.push(a[i]);
    }
    cout << "Karashi cblcd" << endl;
    return 0;
}