#include <bits/stdc++.h>    
using namespace std;
int main()
{
    int n, m, tmp1, tmp2, mark[200005] = {0};
    bool out[11] = {0};
    vector<int> have;
    cin >> tmp1 >> tmp2 >> n >> m;
    int arr[11][1001];
    memset(arr, 0, sizeof(arr));
    have.push_back(tmp1);
    have.push_back(tmp2);
    mark[tmp1] = 1;
    mark[tmp2] = 1;
    for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)cin >> arr[i][j];
    for (int i = 1; i <= m; i++)for (int j = 1; j <= n; j++){
            if (out[j])continue;
            int flag = 0;
            if (mark[arr[j][i]] == 1)flag = -1;
            for (int k = 0; k < have.size(); k++){
                if (mark[arr[j][i] + have[k]] == 1){
                    flag++;
                    mark[arr[j][i]] = 1;
                    have.push_back(arr[j][i]);
                    break;
                }
            }
            if (flag <= 0){
                out[j] = 1;
                cout << "Round #" << i << ": " << j << " is out." << endl;
            }
        }
    bool having = false;
    for (int i = 1; i <= n; i++){
        if (!out[i])
            having = true;
    }
    if (!having){
        cout << "No Winner." << endl;
        return 0;
    }
    else{
        cout << "Winner(s):";
        for (int i = 1; i <= n; i++){
            if (!out[i])
                cout << " " << i;
        }
        cout << endl;
        return 0;
    }
}