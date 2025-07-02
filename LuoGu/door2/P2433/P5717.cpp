#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c; 
    vector<int> tri = {a, b, c};
    if(a+b<=c||a+c<=b||b+c<=a){
        cout << "Not triangle" << endl;
        return 0;
    }
    sort(tri.begin(), tri.end());
    if(tri[0]*tri[0]+tri[1]*tri[1]==tri[2]*tri[2])
        cout << "Right triangle" << endl;
    else if(tri[0]*tri[0]+tri[1]*tri[1]>tri[2]*tri[2])
        cout << "Acute triangle" << endl;
        else cout << "Obtuse triangle" << endl;
        if(a==b||b==c||a==c)
            cout << "Isosceles triangle" << endl;
        if(a==b&&b==c)
            cout << "Equilateral triangle" << endl;
    return 0;
}