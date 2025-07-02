#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    n <<= 1;
    vector<vector<bool>> a(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            a[i][j] = c == 'X';
        }
    }         
    vector<int> num;
    int t = 0, u = n - 1, l = 0, r = n - 1;
    while (t <= u && l <= r) {
        for (int j = l; j <= r; j++)
            num.push_back(a[t][j]);
        t++;
        for (int i = t; i <= u; i++)
            num.push_back(a[i][r]);
        r--;
        if (t <= u) {
            for (int j = r; j >= l; j--)
                num.push_back(a[u][j]);
            u--;
        }
        if (l <= r) {
            for (int i = u; i >= t; i--)
                num.push_back(a[i][l]);
            l++;
        }
    }
    int numm = (n-1)*4;
    int ans[4] = {0};
    for(int i = 0; i < num.size(); i+=numm){
        int cnt=count(num.begin()+i,num.begin()+i+numm,1);
            int pos=find(num.begin()+i,num.begin()+i+numm,1)-(num.begin()+i);
            pos+=cnt/2+1;
            for (int j = 0; j < 4;j++){
                int tmp=j*(n-1);
                if(pos>tmp){
                    ans[j] += tmp + numm - pos;
                }else if(pos<tmp){
                    ans[j] += tmp - pos;
                }
            }
        n-=2;
        numm = (n-1)*4;
    }
    cout<<*min_element(ans,ans+4)<<endl;
    return 0;
}