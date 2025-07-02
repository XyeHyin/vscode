#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> a(n + 1, 0);
    map<int, int> b;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        b[x] = y;
    }
    
    return 0;
}