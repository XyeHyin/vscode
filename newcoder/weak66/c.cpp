#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        string minn = s;
        for(int i = 0; i < s.size(); i++){
            string tmp = s.substr(i) + s.substr(0, i);
            if(tmp < minn)minn = tmp;
        }
        cout << minn << endl;
    }
    return 0;
}