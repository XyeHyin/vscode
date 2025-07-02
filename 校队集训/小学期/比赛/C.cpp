#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a;

    a.push_back(1);
    for (int i = 0; i < n-1;i++){
        a.push_back(a.back() + 50);
    }
    cout << a.back();
    return 0;
}