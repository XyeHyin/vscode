#include <bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int mapp[m][n];
    vector<int> ans;
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            cin >> mapp[m][n];
        }
    }
    int x = 0, y = 0;
    while (m > 0 && n > 0)
    {
        if (m == 1)
        {
            for (int i = 0; i < n; i++)
            {
                ans.push_back(mapp[x][y]);
                y++;
            }
            break;
        }
        else if (n == 1)
        {
            for (int i = 0; i < m; i++)
            {  
                ans.push_back(mapp[x][y]);
                x++;
            }
            break;
        }
        else
        {
            for (int i = 0; i < n - 1; i++)
            {  
                ans.push_back(mapp[x][y]);
                y++;
            }
            for (int i = 0; i < m - 1; i++)
            {   
                ans.push_back(mapp[x][y]);
                x++;
            }
            for (int i = 0; i < n - 1; i++)
            {   
                ans.push_back(mapp[x][y]);
                y--;
            }
            for (int i = 0; i < m - 1; i++)
            {
                x--;
            }
            x++;
            y++;
        }
        m -= 2;
        n -= 2;
    }
    for (int i = 0; i < ans.size();i++){
        cout << ans[i] << " ";
    }
}