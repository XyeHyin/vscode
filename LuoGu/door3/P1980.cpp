#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin >> n>>x;
    vector<int> a(n);
    int count = 0;
    for (int i = 1;i<=n;i++){
        int b = i;
        while(b){
            if(b%10==x)count++;
            b /= 10;
        }
    }
    cout << count << endl;
        return 0;
}