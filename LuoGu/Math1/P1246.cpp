#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if(isalpha(s[i])&&islower(s[i])){
            ans += (s[i]-'a')+(int)pow(26,i);
        }
    }
    cout << ans << endl;
    return 0;
}