#include <bits/stdc++.h>
using namespace std;
#define int long long
struct XyeHyin {
    string name;
    int pv, v;
};
signed main() {
    int n;
    cin >> n;
    vector<XyeHyin> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].name >> a[i].pv >> a[i].v;
    vector<XyeHyin> lsy = a;
    sort(lsy.begin(), lsy.end(),[](XyeHyin a, XyeHyin b) { return a.pv * 2 + b.v > b.pv * 2 + a.v; });
    int anslsy = 0;
    anslsy += lsy[0].pv * 2;
    for (int i = 1; i < n; i++) anslsy += lsy[i].v;
    vector<XyeHyin> hxn = a;
    sort(hxn.begin(), hxn.end(),[](XyeHyin a, XyeHyin b) { return a.pv + b.v * 2 > b.pv + a.v * 2; });
    sort(hxn.begin(), hxn.end()-1,[](XyeHyin a, XyeHyin b) { return a.pv+b.v>b.pv+a.v;});
    int anshxn = hxn[n - 1].v * 2 + hxn[0].pv;
    for (int i = 1; i < n-1; i++) anshxn += hxn[i].v;
    if (anslsy >= anshxn) {
        cout << "LSY" << endl<<anslsy << endl;
        sort(lsy.begin() + 1, lsy.end(),[](XyeHyin a, XyeHyin b) { return a.name < b.name; });
        for (int i = 0; i < n; i++) cout << lsy[i].name << endl;
    } else {
        cout << "HXN" << endl << anshxn << endl;
        sort(hxn.begin()+1, hxn.end()-1,[](XyeHyin a, XyeHyin b) { return a.name < b.name; });
        for (int i = 0; i < hxn.size(); i++) cout << hxn[i].name << endl;
    }
    return 0;
}