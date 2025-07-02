#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != -999) {
            flag = false;
            break;
        }
    }
    if (flag) {
        for(int i=0; i<n; i++){
            if(i%2==0){
                a[i] = 0+x/2;
            }else{
                a[i] = 0-x/2;
            }
        }
        int cnt = 0;
        for(int i=1; i<n; i++){
            if(a[i-1]-a[i]>=x){
                cnt++;
            }
        }
        if(x!=0) cout << cnt << " " << 0 << endl;
        else cout <<n << " " << 0 << endl;
        return 0;
    }
    vector<int> b = a;
    int cntx = 0,cntn=0;
    if(a[0]==-999){
        a[0] = 50;
    }   
    for(int i=1; i<n; i++){
        if(a[i]==-999){
            if(i==n-1){
                if(a[i-1]-x>=-50){
                    cntx++;
                    continue;
                }
            }
            if(a[i-1]-a[i+1]>=2*x){
                a[i]=a[i-1]-x;
                cntx++;
            }else if(a[i-1]-a[i+1]<=x){
                a[i] = 50;
            }else if(a[i-1]-a[i+1]<x*2&&a[i-1]-a[i+1]>x){
                a[i] = a[i-1];
            }
        }
        if(a[i-1]-a[i]>=x){
            cntx++;
        }
    }
    vector<int> c = b;
    if(b[0]==-999){
        b[0] = b[1];
    }
    for(int i=1; i<n; i++){
        if(a[i]==-999){
            if(i==n-1){
                break;
            }
            if(b[i-1]-b[i+1]>=2*x){
                b[i]=b[i-1];
            }else if(b[i-1]-b[i+1]<x){
                b[i] = b[i-1];
            }else if(b[i-1]-b[i+1]<2*x&&b[i-1]-b[i+1]>=x){
                b[i] = b[i-1]-x+1;
            }
        }
        if(b[i-1]-b[i]>=x){
            cntn++;
        }
    }
    cout << cntx << " " << cntn << endl;
    return 0;
}