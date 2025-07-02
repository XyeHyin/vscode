#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a > b;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(),cmp);
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt;i++){
        cout<<arr[i]<<" ";
    }
    cout << endl;
    return 0;
}