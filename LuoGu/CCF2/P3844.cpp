#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    char dic[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            cout << dic[(i + j)%26];
        }
        cout << endl;
    }
        return 0;
}