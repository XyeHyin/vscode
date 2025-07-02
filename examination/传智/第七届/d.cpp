#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
signed main() {
    int n;
    cin >> n;
    int yi = 0, er = 0, san = 0, si = 0;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (a < 0 && b < 0)san++;
        else if (a < 0 && b > 0)er++;
        else if (a > 0 && b > 0)yi++;
        else si++;
    }
    // int yi = 10, er = 8, san = 7, si = 6;
    int ans = 0;
    ans += ((min(yi, san)) + (min(er, si)))*2;
    // cout << "ans:" << ans << endl;
    int tmpa = (min(yi, san)), tmpb = min(er, si);
    yi -= tmpa;
    san -= tmpa;
    er -= tmpb;
    si -= tmpb;
    cout << yi << " " << er << " " << san << " " << si << endl;
    ans += min(yi, si) + min(er, san);
    // cout << "ans:" << ans << endl;
    tmpa = (min(yi, si)), tmpb = min(er, san);
    yi -= tmpa;
    si -= tmpa;
    er -= tmpb;
    san -= tmpb;
    ans += (min(yi, er)) + min(san, si);
    // cout << "ans:" << ans << endl;
    cout << ans << endl;

    return  0;
}