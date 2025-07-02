#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    vector<int> b(a.begin(),a.end());
    sort(b.begin(),b.end());
    int cnt = 0;
    for (int i = 1;i<n;i++)
    {    
        if(a==b){
            break;
        }
        if(a[i]<a[i-1]){
            swap(a[i],a[i-1]);
            i=0;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}