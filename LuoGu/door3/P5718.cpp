#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,min,a[1000];
    cin >> n;
    for (int i = 0; i < n;i++){
        cin>>a[i];
    }
    min = a[0];
    for (int i = 1; i < n;i++){
        if(a[i]<min){
            min = a[i];
        }
    }
    cout << min << endl;
}