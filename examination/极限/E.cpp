#include <bits/stdc++.h>
using namespace std;
int father[1005];
int findfather(int x) {
    return father[x] == x ? x : father[x] = findfather(father[x]);
}
void merge(int x, int y) {
    int fx = findfather(x);
    int fy = findfather(y);
    if(fx!=fy)
        father[fx] = fy;
}
int main() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            return 0;
        }
        int m;
        cin >> m;
        for (int i = 1; i <= n; i++) {
            father[i] = i;
        }
        while(m--){
            int a,b;
            cin >> a >> b;
            merge(a, b);
        }
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(father[i]==i){
                cnt++;
            }
        }
        cout << --cnt << endl;
    }
    return 0;
}