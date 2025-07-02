#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
int n, m;
int a[maxn], c[maxn], pre[maxn];
#define lowbit(x) (x&-x)
int sum(int x){
    int res = 0;
    for(int i=x;i;i-=lowbit(i))res += c[i];
    return res;
}
void add(int x, int y){
    for(int i=x;i<=n;i+=lowbit(i))c[i] += y;
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a[i];
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
        c[i] = pre[i] - pre[i - lowbit(i)];
    }
    while(m--){
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1)add(x, y);
        else cout << sum(y) - sum(x-1) << endl;
    }
    return 0;
}