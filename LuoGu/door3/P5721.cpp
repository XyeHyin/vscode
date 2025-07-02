#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,count=1;
    cin >> n;
    for (int i = n; i >0; i--){
        for (int j = 0; j < i; j++){
            printf("%02d", count++);
        }
        cout << endl;
    }
}