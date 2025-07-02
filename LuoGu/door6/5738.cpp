#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    double ans = 0;
    while(n--){
        vector<int> score(m);
        for (int i = 0; i < m;i++){
            cin >> score[i];
        }
        sort(score.begin(), score.end());
        double total = 0;
        for(int i=1;i<m-1;i++){
            total += score[i];
        }
        ans = max(ans,total / (m - 2));
    }
    printf("%.2f", ans);
    return 0;
}