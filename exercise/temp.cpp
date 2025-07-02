#include <bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ll;
using namespace std;
ll n, a[10000010];
int p[65], ans;
bool ck[65];
unordered_set<int> mm;
#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
template <typename T>
inline void read(T& r) {
    r=0;bool w=0; char ch=getchar();
    while(ch<'0'||ch>'9') w=ch=='-'?1:0,ch=getchar();
    while(ch>='0'&&ch<='9') r=r*10+(ch^48), ch=getchar();
    r=w?-r:r;
}
int find(int x) {
   return p[x]=(x==p[x]?x:p[x]=find(p[x]));
}

void add(int x, int y) { p[find(x)] = find(y); }

void solve() {
    read(n);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    for (int i = 1; i < 64; i++)
        p[i] = i;
    for (int i = 1; i <= n; i++) {
        int j = 0, q;
        bool f = true;
        if (!a[i])ans++;
        while (a[i]) {
            if (a[i] & 1) {
                ck[j] = true;
                if (f) {
                    q = j;
                    f = false;
                } else {
                    add(j, q);
                }
            }
            a[i] >>= 1;
            j++;
        }
    }
    for (int i = 0; i < 64; i++) {
        if (ck[i]) {
            mm.insert(find(i));
        }
    }
    cout << mm.size() + ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    while (t--)
        solve();
    return 0;
}