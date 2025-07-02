#include <bits/stdc++.h>
using namespace std;
    int l, n, k;
    vector<int> a;
bool check(int x){
  
}
int find(int l,int r) { 
        int ans = 0;
    while(l<=r){
        int mid = l + r >> 1;
        if(check){
            ans = mid;
            l = mid+1;
        }else{
            r = mid - 1;
        }
    }
    return l; }
int main(){
    cin >> l >> n >> k;
    a.resize(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int r = a[a.size() - 1];
    int l = 0;
    cout << find(l, r) << endl;
    return 0;
}