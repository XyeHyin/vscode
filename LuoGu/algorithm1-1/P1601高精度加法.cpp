#include <bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    cin >> a >> b;
    if(a.size() < b.size()){
        swap(a,b);
    }
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    while(b.size() < a.size()){
        b += '0';
    }
    int carry = 0;
    string ans;
    for (int i = 0;i<a.size();i++){
        int sum = a[i] - '0' + b[i] - '0' + carry;
        ans += sum % 10 + '0';
        carry = sum / 10;
    }
    if(carry){
        ans += carry + '0';
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
        return 0;
}