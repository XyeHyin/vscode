#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n;i++){
        int a;
        cin >> a;
        q.push(a);
    }
    int ans = 0;
    while(q.size()!=1){
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        ans+=(a+b)*100;
        q.push(a + b);
    }
    cout<<ans<<endl;
    return 0;
}