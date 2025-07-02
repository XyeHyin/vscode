#include <bits/stdc++.h>
using namespace std;
int main() {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            ans ^= tmp;
        }
        if (!ans) cout << "Winner" << endl;
        else cout << "Loser" << endl;
    
}