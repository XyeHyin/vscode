#include <bits/stdc++.h>
using namespace std;
    int ans = 0, k;
    void findkth(int a[], int l, int r){
    if(l==r){
        ans = a[l] ;
        return;
    }
    int i = l, j = r, flag = a[(1 + r) / 2], tmp;
    do{
            while (a[i] > flag) i++;
            while (a[j] < flag) j--;
            if (i <= j) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
                i++;
                j--;
            }} while (i <= j);
            if(k<=j) findkth(a, l, j);
            else if(k>=i) findkth(a, i, r);
    }
    int main(){
        int n, a[100];
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        findkth(a, 1, n);
        cout << ans << endl;
        return 0;
    }
