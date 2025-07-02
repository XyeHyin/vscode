#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c,n;
    cin>>a>>b>>c>>n;
    vector<int> aa(n + 1, 0x3f3f3f3f);
    aa[0] = 0;
    vector<int> bb={a,b,c};
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            if (i - bb[j] >= 0) {
                aa[i] = min(aa[i], aa[i - bb[j]] + 1);
            }
        }
    }
    if(aa[n]==0x3f3f3f3f){
        cout<<-1<<endl;
    }else{
        cout<<aa[n]<<endl;
    }
    return 0;
}