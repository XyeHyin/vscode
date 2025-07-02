#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> saying(n);
    for (int i = 0; i < n;i++){
        cin >> saying[i];
    }
    vector<bool> wolf(n);
    for (int i = 0; i < n;i++){
        if(saying[i]>0){
            wolf[saying[i]] = true;
        }else{
            wolf[saying[abs(i)]] = false;
        }
    }
    for (int i = 0; i < n;i++){
        for (int j = i + 1; j < n;j++){
           
        }
    }
    }
