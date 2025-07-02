#include <bits/stdc++.h>
using namespace std;
vector<int> c;
void f(int begin,int n,int m){
 if(c.size()==n){
     for (int i = 0; i < n;i++){
            cout << c[i] << " ";
     }
     cout << endl;
     return;
 }
 for (int i = begin; i < m;i++){
     c.push_back(i);
     f(i + 1, n, m);
     c.pop_back();
 }
}
int main(){
    int n, m;
    cin>>n>>m;
    f(0,n, m);
    return 0;
}