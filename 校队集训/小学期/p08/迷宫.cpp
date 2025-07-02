#include <bits/stdc++.h>
using namespace std;
char mp[30][50]={0};
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int ans = 0x3f3f3f3f;
int n=4,m=6;
string res="";
string s="";
void dfs(int x,int y,int step){
    if(x==n-1&&y==m-1){
        int temp = ans;
        if(temp==step){
            res=min(res,s);
        }
        ans=min(ans,step);
        if(temp!=ans){
            res = s;
        }
        return;
    }
    for (int i = 0; i < 4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0&&nx<n&&ny>=0&&ny<m&&mp[nx][ny]=='0'){ 
            if(i==0){
            s += 'R';
        }else if(i==1){
            s += 'D';
        }else if(i==2){
            s += 'L';
        }else if(i==3){
            s += 'U';
        }
            mp[nx][ny] = 1;
            dfs(nx, ny, step + 1);
            s.pop_back();
            mp[nx][ny] = 0;
        }
}
}
int main(){ 
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> mp[i][j];
        }
    }
    dfs(0, 0,0);
    cout<<ans<<endl;
    cout << res << endl;
    return 0;
}