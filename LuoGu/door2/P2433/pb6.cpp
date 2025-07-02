#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,local,luogu;
    cin >> n;
    local = n * 5;
    luogu = n * 3 + 11;
    if(local<luogu){
        cout << "Local" << endl;
    }else{
    cout << "Luogu" << endl;
    }
    return 0;
}