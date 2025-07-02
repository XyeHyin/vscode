#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> right(7);
    for(int i=0;i<7;i++){
        cin>>right[i];
    }
    int num;
    int countt[8]={0};
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<7;j++){
            cin >> num;
            for(int k=0;k<7;k++){
                if(num==right[k]){
                    cnt++;
                    break;
                }
            }
        
        }
        countt[cnt-1]++;
    }
        for(int i=6;i>=0;i--){
            cout << countt[i] << " ";
            }
        
    return 0;
}