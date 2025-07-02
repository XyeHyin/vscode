#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int x, k;
    pair<int,int> m=make_pair(0,0);
    for (int i = 1;i*364<n&&i<=100;i++){
        for (int j =200;j>=1;j--){
            if(i*364+j*1092==n){
                    m.first = i;
                    m.second = j;
            }
        }
    }
    cout<<m.first<<endl<<m.second<<endl;
        return 0;
}