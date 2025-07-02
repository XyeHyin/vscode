#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define PII pair<int, int>
#define dbg(x) std::cout << #x << ":" << x << " "
#define MP make_pair
#define PB push_back
#define rep(i,x,n) for(int i=x;i<=n;i++)
#define dep(i,x,n) for(int i=x;i>=n;i--)
#define arrout(a,n) rep(i,1,n)std::cout<<a[i]
#define arrin(a,n) rep(i,1,n)std::cin>>a[i]
#define endl '\n'
class Solution {
  public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
        int j = mat.size(), i = mat[0].size();
        int ii = i, jj = j;
        for (; i > 0;i--){
            vector<int> a;
            int iii = i;
            for (int jjj = 0; jjj < j && iii < ii;jjj++,iii++){
                a.push_back(mat[jj][iii]);
            }
            sort(a.begin(), a.end());
            iii = i;
            for (int jjj = 0; jjj < j && iii < ii; jjj++, iii++) {
                mat[jjj][iii] = a[jjj];
            }
        }
        for (; j > 0;j--){
            vector<int> a;
            int jjj = j;
            for (int iii = 0; iii < i && jjj < jj;jjj++,iii++){
                a.push_back(mat[jjj][ii]);
            }
            sort(a.begin(), a.end());
            jjj = j;
            for (int iii = 0; iii < i && jjj < jj;jjj++,iii++){
                mat[jjj][iii] = a[iii];
            }
        }
    }
};