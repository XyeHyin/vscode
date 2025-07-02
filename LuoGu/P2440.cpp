#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> l(n);
    int maxL = 0;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        maxL = max(maxL, l[i]);
    }

    int left = 1, right = maxL;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long total = 0;
        for (int i = 0; i < n; i++) {
            total += l[i] / mid;
        }
        if (total >= k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << right << endl;
    return 0;
}