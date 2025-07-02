#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n;
    getchar();
    for (int i = 0; i < n;i++){
        char alpha,flag;
        for (int j = 0; j < 4;j++){
            scanf("%c-%c", &alpha, &flag);
            getchar();

            if(flag=='T'){
                s += ('0'+alpha-'A'+1);
            }
        }
    }
    cout << s<<endl;
}