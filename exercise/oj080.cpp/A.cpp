#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[20005]={0},max=0;
    vector<int> ans;
    for (int i = 0; i < n;i++){
        int temp;
        cin >> temp;
        a[temp]++;
    }
    for (int i = 10000; i <= 20000; i++){
        if(a[i]>max) {
            max = a[i];
            ans.clear();
            ans.push_back(i);
            }
        else if(a[i]==max) ans.push_back(i);
    }
    for (int i = 0; i < ans.size();i++){
        if(i!=0) cout << " ";
        cout << ans[i];
    }
}