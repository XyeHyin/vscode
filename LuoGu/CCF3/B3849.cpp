    #include <bits/stdc++.h>
    using namespace std;
    string dic="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int main(){
        int n, r;
        cin >> n >> r;
        string ans = "";
        while(n){
            ans = dic[n % r] + ans;
            n /= r;
        }
        cout << ans;
        return 0;
    }