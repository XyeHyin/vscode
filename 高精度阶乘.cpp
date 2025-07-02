#include <bits/stdc++.h>
using namespace std;
#define maxn 100
struct Bigint
{
    int len, a[maxn];
    Bigint(int x = 0){
        memset(a, 0, sizeof(a));
        for (len = 1; x; len++)
            a[len] = x % 10, x /= 10;
        len--;
    }
    int &operator[](int i){
        return a[i];
    }
    void flatten(int L) {
        len = L;
        for (int i = 1; i <= len; i++)
            a[i + 1] += a[i] / 10, a[i] %= 10;
        for (; !a[len];)
            len--;
    }
    void print(){
        for (int i = max(len, 1); i >= 1; i--)
            printf("%d", a[i]);
    }
};
Bigint operator*(Bigint a, int b){
    Bigint c;
    int len = a.len;
    for (int i = 1; i <= len; i++)
        c[i] = a[i] * b;
    c.flatten(len + 4);
    return c;
}
int main(){
    Bigint ans(1);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * i;
    }
    ans.print();
    return 0;
}