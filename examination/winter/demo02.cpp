#include <bits/stdc++.h>
using namespace std;

int main(){
     long x1, x2, y1, y2, sumx, sumy;
     int  a[30], b[30];
    bool isflag = true;
    cin >> x1 >> x2 >> y1 >> y2;
    for (int i = 0; i < 24;i++){
        cin >> a[i];
        sumx += a[i];
    }
    for (int i = 0; i < 24; i++)
    {
        cin >> b[i];
        sumy += b[i];
    }
    for (int i = 0; i < 24;i++){
            if(a[i]<x2||sumx<x1||b[i]<y2||sumy<y1){
                isflag = false;
            }
    }
    if(isflag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}