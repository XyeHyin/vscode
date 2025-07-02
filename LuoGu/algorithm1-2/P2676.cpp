#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, b;
    cin >> n >> b;
    vector<int> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end(),greater<int>());
    int sum = 0;
    for(int i = 0;i<n;i++){
        sum+=a[i];
        if(sum>=b){
            cout<<i+1;
            return 0;
        }
    }
    return 0;
}