#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    int _;
    cin >> _;
    vector<int> b;
    vector<int> ans;
    while(_--){
        int a;
        cin >> a;
        ans.push_back(arr[a]);
        b.push_back(arr[a]);
        sort(b.begin(), b.end());
        int cnt = 0;
        for(int i = 0;i<ans.size();i++){
           if(ans[i]!=b[i]){
               cnt++;
           }
        }
            cout << cnt-(cnt==0?0:1) << endl;
        sort(ans.begin(), ans.end());
    }
    return 0;
}