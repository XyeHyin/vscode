#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<queue<int>> windows(m);
    vector<int> last(m, 0);
    for (int i = 0; i < m && i < n; i++) windows[i].push(a[i]);
    for (int i = m; i < n; i++){
        int min_index = 0;
        for (int j = 1; j < m; j++){
            if (windows[j].front() < windows[min_index].front()){
                min_index = j;
            }
        }
        int p = windows[min_index].front();
        windows[min_index].pop();
        if (p < last[min_index]){
            cout << "Karashi lovelove" << endl;
            return 0;
        }
        last[min_index] = p;
        windows[min_index].push(a[i]);
    }
    cout << "Karashi cblcd" << endl;
    return 0;
}