#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int i = 0,sum=0x3f3f3f3f;
    while(true){
        if(i+m>n){
            break;
        }
      int temp = accumulate(a.begin()+i,a.begin()+i+m,0);
      sum=min(sum,temp);
        i++;
    }
    cout<<sum<<endl;
        return 0;
}