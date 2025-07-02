#include <bits/stdc++.h>
using namespace std;
struct student {
    int yu, shu, ying, tot;
    int id;
};
bool cmp(student a, student b) {
    if (a.tot != b.tot)
        return a.tot > b.tot;
    if (a.yu != b.yu)
        return a.yu > b.yu;
    return a.id < b.id;
}
int main() {
    int n;
    cin >> n;
    vector<student> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].yu >> a[i].shu >> a[i].ying;
        a[i].tot = a[i].yu + a[i].shu + a[i].ying;
        a[i].id = i + 1;
    }
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < 5; i++) {
        cout << a[i].id << " " << a[i].tot << endl;
    }
    return 0;
}