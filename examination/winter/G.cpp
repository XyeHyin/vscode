#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d;
    bool isflag = false;
    cin >>a>>b>>c>>d;
    for (int x = a+1; x<=c; x++){
        for (int y = b+1; y<= d; y++){
            if ((x * y) % (a * b) == 0)
            {
                isflag = true;
                break;
            }
        }
        if (isflag){ 
            break;
        }
    }
    if(isflag){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}