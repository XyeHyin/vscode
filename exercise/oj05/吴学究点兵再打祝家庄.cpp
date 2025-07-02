#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c, d, e, f, g, h;
    while(cin>>a>>b>>c>>d>>e>>f>>g>>h){
        for (int i = g; i <= h;i++){
            if(i%a==b&&i%c==d&&i%e==f){
                cout << i << endl;
                break;
            }
        }
    }
}