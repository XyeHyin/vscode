#include <bits/stdc++.h>
using namespace std;
int main(){
    // vector<int> a(100);
    // for(int i=0;i<100;i++){
    //     a[i]=i+1;
    // }
    // for(int i=0;i<100;i++){
    //     int mo=a[i]%10;
    //     int shou=a[i]/10;
    //     if(mo==2||mo==3||mo==7||mo==8){
    //         a[i]=0;
    //     }
    //     if(shou==2||shou==3||shou==7||shou==8){
    //         a[i]=0;
    //     }
    // }
    // int count = 0;
    // for(int i=10;i<100;i++){
    //     string s=to_string(a[i]);
    //     if(s.size()==2){
    //         count++;
    //     }
    // }
    vector<int> a(100,0);set<int> se;
    for(int i=0;i<100;i++){
        a[i]=pow(i,2);
    }
    for(int i=4;i<100;i++){
        string s=to_string(a[i]);
        se.insert(stoi(s.substr(s.size()-2,2)));
    }
    cout<<se.size();

    return 0;
}