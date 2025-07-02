#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
vector<int> c;
int ans = 0;
int result = 0;
void f(int num, int a, int b) {
    if (c.size() == a) {
        int j = 0;
        sort(c.begin(), c.end());
        vector<int> sum;
        int summing = 0;
        for (int i = 0; i < arr.size(); i++) {
            summing += arr[i];
            if (c[j] == i) {
                sum.push_back(summing);
                summing = 0;
                j++;
            }
        }
        for (int i = 0; i < sum.size(); i++) {
            ans += (i + 1) * sum[i];
        }
        result = max(result, ans);
        ans = 0;
        return;
    }
    if (num >= b)
        return;
    c.push_back(num);
    f(num + 1, a, b);
    c.pop_back();
    f(num + 1, a, b);
}
int main() {
    int n;
    cin >> n;
    for (int j = 0; j < n; j++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int banzi = n / 2 - 1;
    f(0, banzi, n + banzi);
    cout << ans << endl;
    return 0;
}