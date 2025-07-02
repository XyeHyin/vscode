#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a = {1,3,6,9,2};
    sort(a.begin(), a.end(),[](int x,int y){
        return x > y;
            });
    return 0;
}