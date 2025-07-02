#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n>>s;
    if(n==1){
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    }else{
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    }
    cout<<s<<endl;
    return 0;
}