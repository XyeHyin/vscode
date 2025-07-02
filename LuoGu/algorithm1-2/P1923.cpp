#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int main(){
    int n,k;
    n=read();k=read();
    vector<int> a(n);

    for (int i = 0; i < n;i++){
        a[i] = read();  
    }
    nth_element(a.begin(),a.begin()+k,a.end());
    cout << a[k];
        return 0;
}