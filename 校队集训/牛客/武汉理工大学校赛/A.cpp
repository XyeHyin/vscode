#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<string> s(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >>s[i];
        cin >>a[i];
    }
    int w;
    cin >> w;
    for (int i = 0; i < w;i++){
        string s1;
        cin >> s1;
        for (int j = 0; j < n;j++){
            if(s[j]==s1){
                b[j]++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n;i++){
        if(a[i]==b[i]){
            ans++;
        }
    }
    cout << ans << endl;
}