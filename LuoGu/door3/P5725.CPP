#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int count = 1,cnt = 0;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            printf("%02d",count++);
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 1;i<=n;i++){
        for (int j = 1; j <= n;j++){
            if(j<n-i+1)printf("  ");
            else printf("%02d",++cnt);
        }
        cout << endl;
    }
        return 0;
}