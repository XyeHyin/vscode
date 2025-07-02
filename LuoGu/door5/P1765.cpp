#include <bits/stdc++.h>
using namespace std;
int main(){
    int lst[27]={1,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
    string s;
    getline(cin, s);
    int cnt = 0;
    for (int i = 0; i < s.size();i++){
        if(s[i]==' '){
            cnt += lst[0];
        }else{
            cnt += lst[s[i] - 'a'+1];
        }
    }
    cout << cnt;
        return 0;
}