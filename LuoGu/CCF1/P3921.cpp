#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a>>b;
    int dic[]={7,1,2,3,4,5,6};
    cout<<dic[(a+b)%7]<<endl;
    return 0;
}