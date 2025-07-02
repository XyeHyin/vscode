// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// signed main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         if(n==2){
//             cout<<1<<endl;
//             continue;
//         }
//         int ans = pow(2, ceil(log2(n)));
//         cout << ans << endl;
//     }
//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// signed main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         if(n==2){
//             cout<<1<<endl;
//             continue;
//         }
//         int ans = 1;
//         while (ans <= n) {
//             ans *= 2;
//         }
//         cout << ans << endl;
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unordered_set<int> a;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout<<i<<" "<<j<<" "<<(i^j)<<endl;
                a.insert(i ^ j);
            }
        }
        int cnt = 0;
        for(auto i : a){
            cout << i << " ";
        }
        while (a.count(cnt)) cnt++;
        cout << cnt << endl;
    }
    return 0;
}