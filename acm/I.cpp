#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        vector<int> coin = {15,10,6,3,1};
        int cnt = 0;
        while(a){
            for(int i = 0; i < coin.size(); i++){
                if(a >= coin[i]){
                    cout<<coin[i]<<endl;
                    a -= coin[i];
                    cnt++;
                    break;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}