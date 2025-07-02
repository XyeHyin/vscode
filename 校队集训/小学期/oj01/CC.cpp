#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i] * (i + 1);
    }
    vector<int> houzhui;
    int temp = 0;
    for(int i = n-1; i>0; i--){
        houzhui.push_back(arr[i] + temp);
        temp = houzhui.back();
    }
    sort(houzhui.begin(),houzhui.end());
    for (int i = 0;i<n/2;i++){
        sum -= houzhui[i];
    }
    cout << sum;
        return 0;
}