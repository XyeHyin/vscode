#include <bits/stdc++.h>
using namespace std;
int mpa[101][101] = {0};
int mpb[101][101] = {0};
int mpc[101][101] = {0};
int main(){
    int n,a,b,c;
    cin >> n>>a>>b>>c;
    for (int i = 1;i<=a;i++){
        int x, y;
        cin >> x >> y;
        mpa[x][y] = 1;
    }for (int i = 1;i<=b;i++){
        int x, y;
        cin >> x >> y;
        mpb[x][y] = 1;
    }for (int i = 1;i<=c;i++){
        int x, y;
        cin >> x >> y;
        mpc[x][y] = 1;
    }
    while(n--){
        int x, y, r;
        cin >> x >> y >> r;
        for(int i=x-r;i<=x+r;i++){
            for(int j=y-r;j<=y+r;j++){
                if(i>=1&&i<101&&j>=1&&j<101&&(x==i||y==j)){
                    mpa[i][j] = 0;
                    mpb[i][j] = 0;
                    mpc[i][j] = 0;
                }
            }
        }
    }
    int cnta = 0, cntb = 0, cntc = 0;
    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            if(mpa[i][j]){
                cnta++;
            }if(mpb[i][j]){
                cntb++;
            }if(mpc[i][j]){
                cntc++;
            }
        }
    }
    cout << cnta << " " << cntb << " " << cntc << endl;
        return 0;
}