#include <bits/stdc++.h>
using namespace std;
int main(){
    int l,m;
    cin>>l>>m;
    vector<int> tree(l + 1, 1);
    for(int i=0;i<m;i++){
        int be, en;
        cin>>be>>en;
        for(int j=be;j<=en;j++){
            tree[j]=0;
        }
    }
    cout << count(tree.begin(), tree.end(), 1) << endl;
    return 0;
}