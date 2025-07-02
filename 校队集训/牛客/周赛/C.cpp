#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n + 1, 0), b(n + 1, 0);
    for (int i = 0; i < n; i++){
        a[i + 1] = a[i] + (islower(s[i]) ? 1 : 0);
    }
    for (int i = n - 1; i >= 0; i--){
        b[n - i] = b[n - i - 1] + (isupper(s[i]) ? 1 : 0);
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i < n; i++){
        ans = min(ans, a[i] + b[n - i]);
    }
    cout << ans << endl;
    return 0;
}