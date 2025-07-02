#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a;
    for (int i = 0; i < 10;i++){
        int n=rand()%9;
        a.push_back(n);
    }
    for (int i = 0; i < 10;i++){
        cout << a[i] << " ";
    }
        return 0;
}