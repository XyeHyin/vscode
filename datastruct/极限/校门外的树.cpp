#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int l, m;
    cin >> l >> m;
    vector<int> a(l + 10, 1);
    while (m--) {
        int aa, bb;
        cin >> aa >> bb;
        for (int i = aa; i <= bb; i++)
            a[i] = 0;
    }
    int ans = 0;
    for(int i=0;i<=l;i++) ans+=a[i];
     cout << ans << endl;    
    if(a[217])cout << "Little_X" << endl;
    else cout<<"Nothing"<<endl;
    if(a[316])cout << "Little_H" << endl;
    else cout<<"Nothing"<<endl;
    return 0;
}