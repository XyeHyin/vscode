#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int mp[7][7]={0};
int cnt = 0;
void dfs(int x,int y){
  if(x==0||y==0||x==6||y==6){
      cnt++;
      return;
  }
  for (int i = 0; i < 4;i++){
      int endx=x+dx[i], endy=y+dy[i];
      if (!mp[endx] [endy]) {
          mp[endx][endy] = 1;
          mp[6 - endx][6 - endy] = 1;
          dfs(endx, endy);
          mp[endx][endy] = 0;
          mp[6 - endx][6 - endy] = 0;
      }
  }
}
int main(){
    mp[3][3] = 1;
    dfs(3, 3);
    cout << cnt/4 << endl;
    return 0;
}