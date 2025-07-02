#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    priority_queue<int,vector<int>,greater<int>> q;
    while(n--){
        int a;
        cin >> a;
        q.push(a);
    }
    int cnt = 0;
    while(q.size()!=1){
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        cnt+=a+b;
        q.push(a+b);
    }
    cout << cnt;
    return 0;
}