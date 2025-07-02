#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    vector<int> arr1(n), arr2(n);
    arr1[0] = 1;
    for (int i = 1; i < n;i++){

        if(a[i] > a[i-1]){
            arr1[i] = arr1[i-1] + 1;
        }else{
            arr1[i] = 1;
        }
    }
    arr2[n-1] = 1;
    for(int i=n-2;i>=0;i--){
        if(a[i] >a[i+1]){
            arr2[i] = arr2[i+1] + 1;
        }else{
            arr2[i] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n;i++){
        ans += max(arr1[i], arr2[i]);
    }
    cout << ans << endl;
}