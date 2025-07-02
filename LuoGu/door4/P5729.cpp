#include <bits/stdc++.h>
using namespace std;
int main(){
    int w, x, h, q;
    cin >> w >> x >> h >> q;
    int a[w+1][x+1][h+1]={0};
    while(q--) {
      int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for(int i = x1; i <= x2; i++)
            for(int j = y1; j <= y2; j++)
                for(int k = z1; k <= z2; k++)
                    a[i][j][k] = 1;
    }
    int count = 0;
    for(int i = 1; i <= w; i++)
        for(int j = 1; j <= x; j++)
            for(int k = 1; k <= h; k++)
                if(a[i][j][k] == 0)
                    count++;
     cout<<count<<endl;
    return 0;
}