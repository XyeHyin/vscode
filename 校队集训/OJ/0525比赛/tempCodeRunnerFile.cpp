#include <bits/stdc++.h>
using namespace std;
int main(){
    for (int k = 0;k<5;k++){
        int n;
        cin >> n;
        if(n==0){
            cout << 0 << endl;
            continue;
        }
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2;j++){
                cin >> a[i][j];
            }
        }
        int count = 1;
        pair<int, int> temp=make_pair(a[0][0],a[0][1]);
        for (int i = 1; i < n;i++){
           if((a[i][0]>temp.first&&a[i][1]>temp.second)||(a[i][0]>=temp.first&&a[i][1]>temp.second)||(a[i][0]>temp.first&&a[i][1]>=temp.second)){
               count++;
               temp.first = a[i][0];
               temp.second = a[i][1];
           }
        }
        cout << count << endl;
    }
}