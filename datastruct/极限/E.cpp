#include <bits/stdc++.h>
using namespace std;
struct Student {
    string name;
    int yw, sx, yy, lz, wz;
    int total;
};
bool cmp( Student a, Student b) {
    if (a.total != b.total)return a.total > b.total;
    if (a.sx != b.sx)return a.sx > b.sx;
    if (a.yw != b.yw)return a.yw > b.yw;
    if (a.yy != b.yy)return a.yy > b.yy;
    if (a.wz != b.wz)return a.wz > b.wz;
    return a.name < b.name;
}
int main() {
    int n;
    cin >> n;
    vector<Student> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].name >> a[i].yw >> a[i].sx >> a[i].yy >> a[i].lz >> a[i].wz;
        a[i].total = a[i].yw + a[i].sx + a[i].yy + a[i].lz + a[i].wz;
    }
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < 5; i++) {
        cout << a[i].name << endl;
    }
    int aa, bb;
    for(int i=0;i<n;i++){
        if (a[i].name == "Little_X") aa=i;
        if (a[i].name == "Little_H") bb=i;
    }
    cout << abs(aa - bb) << endl;
    return 0;
}