#include <bits/stdc++.h>
using namespace std;
int main(){
    string s="123456789";
    do{
        double a = stod(s.substr(0, 3));
        double b = stod(s.substr(3, 3));
        double c = stod(s.substr(6, 3));
        if(b/a==2&&c/a==3){
            cout << a << " " << b << " " << c << endl;
        }
    }while (next_permutation(s.begin(),s.end()));
    return 0;
}