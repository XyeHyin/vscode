#include <bits/stdc++.h>
using namespace std;
struct bir{
    string name;
    int y, m, d,id;
};
bool cmp(bir a, bir b){
    if(a.y==b.y){
        if(a.m==b.m){
            if(a.d==b.d){
                return a.id > b.id;
            }
            return a.d < b.d;
        }
        return a.m < b.m;
    }
    return a.y < b.y;
}
int main(){
    int n;
    cin >> n;
    vector<bir> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].name >> a[i].y >> a[i].m >> a[i].d;
        a[i].id = i;
    }
    sort(a.begin(), a.end(), cmp);
    for(int i = 0; i < n; i++){
        cout << a[i].name << endl;
    }
    return 0;
}