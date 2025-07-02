#include <bits/stdc++.h>
using namespace std;
int a[20]={0};
int count = 0;
bool test(int n, int m, int i) {
    int j;
    for (j = 0; j < m; j++) {
        if (a[j]==i||a[j]==m+i-j||a[j]==j+i-m) {
            return false;
        }
    }
    return true;
}
void hh1(int n, int m) {
    if (m == n) {
        int i, j;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if(a[i]==j) cout << "1 ";
                else cout << "0 ";  
            }
            cout << endl;
        }
        // cout << endl;
        ++::count;
        return;
    }
    int i;
    for (i = 0; i < n; i++) {
        if (test(n , m, i)) {
            a[m]=i;
            hh1(n, m + 1);
            //a[m][i] = 0;
        }
    }
}
void hh(int n) {
    int a[n];
    memset(a, 0, sizeof(int)*n);
    int count = 0;
    hh1(n, 0);
}
int main() {
    int _;
    cin >> _;
    hh(_);
    cout << ::count;
    return 0;
}