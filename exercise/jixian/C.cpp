#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n==1){
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        cout << s;
    }else{
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        cout << s;
    }
    return 0;
}