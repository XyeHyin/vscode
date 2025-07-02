#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    bool flag;
    if (h[1] >= h[0]) {
        flag = 1;
    } else {
        flag = 0;
    }
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if(i == n - 1&&!flag){
            cnt++;
            break;
        }
        if (h[i + 1] < h[i]) {
            if (flag) {
                cnt++;
                flag = 0;
            }
        } else if (h[i + 1] > h[i]) {
            if (!flag) {
                cnt++;
                flag = 1;
            }
        }
    }
    cout << cnt;
    return 0;
}