#include <bits/stdc++.h>
using namespace std;
int main()
{
    int row, col;
    cin >> row >> col;
    int grid[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]==1){
                if(grid[i-1][j]==0||i-1<0){
                    ans++;
                }
                if(grid[i+1][j]==0||i+1>=row){
                    ans++;
                }
                if(grid[i][j-1]==0||j-1<0){
                    ans++;
                }
                if(grid[i][j+1]==0||j+1>=col){
                    ans++;
            }
        }
    }
}
cout << ans << endl;
}