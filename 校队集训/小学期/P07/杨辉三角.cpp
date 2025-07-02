#include <bits/stdc++.h>
using namespace std;
#define int long long
int zuhe(int n, int m) {
    if (n > m)
        return 0;
    if (n == 0 || n == m)
        return 1;
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result = result * (m - i + 1) / i;
    }
    return result;
}
signed main(){
    
    int n;
    cin >> n;
    vector<int> a;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1;;i++){
        if((1<<i) < n){
            continue;
        }
        else{
            int left = 1,right=i;
            while(left < right){
                int mid = (left + right) / 2;
                int temp = zuhe(mid, i);
                if(temp > n){
                    right = mid-1;
                }
                else if(temp < n){
                    left = mid+1;
                }else{
                    cout << (1+i)*i/2+mid << endl;
                    return 0;
                }
            }
        }
    }
        return 0;
}