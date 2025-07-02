#include <bits/stdc++.h>
using namespace std;
int main(){
    double a, b, c;
    cin >> a >> b >> c;
    string s = "123456789";
    int cnt = 0;
    do{
        double x = stod(s.substr(0, 3));
        double y = stod(s.substr(3, 3));
        double z = stod(s.substr(6, 3));
        if(y==x*b/a&&z==x*c/a){
            cout << x << " " << y << " " << z << endl;
            cnt++;
        }
    }while(next_permutation(s.begin(), s.end()));
    if(!cnt){
        cout << "No!!!" << endl;
    }
    return 0;
}