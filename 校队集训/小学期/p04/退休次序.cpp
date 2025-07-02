#include <bits/stdc++.h>
using namespace std;
struct teacher {
    string shenfenzheng, shijian;
};
bool cmp(teacher a, teacher b) {
    if (a.shijian != b.shijian) return a.shijian < b.shijian;
    return a.shenfenzheng < b.shenfenzheng;
}
int main() {
    int n;
    cin >> n;
    vector<teacher> s(n);
    for (int i = 0; i < n; i++) {
        string ss;
        cin >> ss;
        if (ss[s.size() - 1] == 'X')
            ss[s.size() - 1] = 0;
        string time = to_string(stoi(ss.substr(6, 4)) +
                                ((ss[16] - '0') % 2 == 0 ? 55 : 60));
        time += ss.substr(10, 4);
        s[i].shenfenzheng = ss;
        s[i].shijian = time;
    }
    sort(s.begin(), s.end(), cmp);
    for (int i = 0; i < s.size(); i++) {
        cout << s[i].shenfenzheng << " " << s[i].shijian << endl;
    }
    return 0;
}