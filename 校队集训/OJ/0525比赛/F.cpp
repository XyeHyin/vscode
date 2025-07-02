#include <bits/stdc++.h>
using namespace std;
bool cmp(vector<int> a, vector<int> b){
    if (a[0] == b[0]&&a[0]!=b[0])return a[1] < b[1];
    if (a[1] == b[1]&&a[0]!=b[0]) return a[0] < b[0];
    return a[0]<b[0] && a[1] < b[1];
}
int main(){
    for (int k = 0;k<5;k++){
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(2));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < 2;j++){
                cin >> a[i][j];
            }
        }
        if (n == 0){
            cout << 0 << endl;
            continue;
        }
        if (n == 1){
            cout << 1 << endl;
            continue;
        }
        sort(a.begin(), a.end(),cmp);
        for(auto i:a){
            cout << i[0] << " " << i[1] << endl;
        }
        // int count = 1;
        // pair<int, int> temp=make_pair(a[0][0],a[0][1]);
        // for (int i = 1; i < n;i++){
        //    if(a[i][0]>temp.first&&a[i][1]>temp.second){
        //        count++;
        //        temp.first = a[i][0];
        //        temp.second = a[i][1];
        //    }
        // }
        // cout << count << endl;
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++){
            for (int j = 0; j < i; j++){
                if (a[i][0] > a[j][0] && a[i][1] > a[j][1]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        cout << *max_element(dp.begin(), dp.end()) << endl;
    }
}