#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    reverse(s.begin(),s.end());
    cout<<stoi(s)<<endl;
    return 0;
}