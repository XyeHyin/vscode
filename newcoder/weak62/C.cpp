#include <bits/stdc++.h>
using namespace std;
#define double long double
const double PI = 3.14159265358979323846;

int main() {
    int n, k;
    cin >> n >> k;
    vector<double> a;
    for (int i = 0; i < n; i++) {
        double x, y, r;
        cin >> x >> y >> r;
        double d = sqrt(x * x + y * y);
        if (d < r) {
            a.push_back(PI * r * r * (r - d));
        }else{
            a.push_back(0);
        }
    }
    sort(a.begin(), a.end());
    double ans = 0;
    for (int i = 0; i < n - k; i++) {
        ans += a[i];
    }
    printf("%.17Lf", ans);
    return 0;
}