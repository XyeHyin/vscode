#include <bits/stdc++.h>
using namespace std;
struct Chik {
    int nan, nv, xiao;
};
int main() {
    int _;
    cin >> _;
    while (_--) {
        int a;
        cin >> a;
        int cnt = 0;
        vector<Chik> v;
        for (int i = 0; i < a / 5; i++) {
            for (int j = 0; j < (a - i) / 3; j++) {
                if((a-i-j)%3!=0) continue;
                if (i * 5 + j * 3 + (a - i- j)/3 == a) {
                    cnt++;
                    v.push_back({i, j, a - i - j});
                }
            }
        }
        cout << cnt << endl;
        for (int i = 0; i < v.size(); i++) {
            cout << v[i].nan << " " << v[i].nv << " " << v[i].xiao << endl;
        }
    }
}