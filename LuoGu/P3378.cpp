#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> p;
    while(n--){
        int a;
        cin >> a;
        if(a == 1){
            int b;
            cin >> b;
            p.push(b);
        }
        else if(a == 2){
            cout << p.top() << endl;
        }else{
            p.pop();
        }
    }
    return 0;
}