#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=3;i<=n;i++){
       if(i%3==0||i%7==0) {
           if (i != 3)cout << " ";
           cout << i;
    }
}
cout << endl;
}