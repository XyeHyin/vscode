#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < n; i++){
        cin>>b[i];
    }
    for(int i = 0; i < n; i++){
        if(a[i] > b[i]){
            cout << "WinWinWin!!!" << endl;
            return 0;
        }
    }
    for (int i = 0; i < n;i++){
        for(int j = 0; j < n; j++){
            if(a[i] > b[j]){
                cout << "HaHa" << endl;
                return 0;
            }
        }
    }
    cout << "AreYouOK?" << endl;
    return 0;
}