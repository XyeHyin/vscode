#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    set<int> s;
    priority_queue<int, vector<int>, greater<int>> pq;
    int dic[]={2,3,5,7};
    for(int i=0;i<4;i++){
        pq.push(dic[i]);
        s.insert(dic[i]);
    }
   if(n==0||n==1||n==2||n==3||n==5||n==7){
        cout<<n<<endl;
        return 0;
   }
    int index = 0;
    while (!pq.empty()) {
        int tmp = pq.top();
        pq.pop();
        index++;
        if (index + 1 == n) {
            cout << tmp << endl;
            return 0;
        }
        for(int i=0;i<4;i++){
            if (s.find(tmp * dic[i]) == s.end()) {
                pq.push(tmp * dic[i]);
                s.insert(tmp * dic[i]);
            }
        }
    }
    return 0;
}