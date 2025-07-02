#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int tmp = 0, tt = 0;
    for (int i = 1; i < n; i++) {
        if(a[i]==0){
            cout << "NO" << endl;
            return 0;
        }
        if (a[i] != a[i - 1]) {
            tt = 0;
            tmp++;
        }
        if (a[i] == a[i - 1]) {
            tt++;
        }
        if (tt >= 2) {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (tmp < n / 2) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}