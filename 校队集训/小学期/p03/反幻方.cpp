#include <bits/stdc++.h>
using namespace std;
int matrix[]={1,2,3,4,5,6,7,8,9};
int mp[9]={0};
int cnt = 0;
bool check() {
    set<int> se;
    se.insert(mp[0] + mp[1] + mp[2]);
    se.insert(mp[3] + mp[4] + mp[5]);
    se.insert(mp[6] + mp[7] + mp[8]);
    se.insert(mp[0] + mp[3] + mp[6]);
    se.insert(mp[1] + mp[4] + mp[7]);
    se.insert(mp[2] + mp[5] + mp[8]);
    se.insert(mp[0] + mp[4] + mp[8]);
    se.insert(mp[2] + mp[4] + mp[6]);

    
    return se.size() == 8;
    }
void dfs(int step) {
    if(step==9){
        if(check()){
            cnt++;
        }
        return;
    }
    for (int i = 0; i <= 8; i++) {
        if(!mp[i]){
            mp[i] = matrix[step];
            dfs(step + 1);
            mp[i] = 0;
        }
    }
}
int main() {
    dfs(0);
    cout << cnt/8 << endl;
    return 0;
}