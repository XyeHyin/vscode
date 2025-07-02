#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 9999999;
    for (int i = n; i >= 0; i--) {
        string s = to_string(n);
        vector<int> v((int)s.size());
        int tmp = s.size();
        for(int j = 0; j < tmp; j++) {
            v[j] = s[j] - '0';
        }
        while (1) {
            for (int j = 0; j < tmp;j++){
                for(int k = 0; k < tmp; k++){
                    if(j!=k){
                        v[j] = (v[j] + v[k]);
                    }
                }
                if(v[j]==i) {
                    cout << i << endl;
                    break;
                }
                else if(v[j] > i) {
                    goto end;
                }
            }
        }
        end:;
       
    } 
    return 0;
}