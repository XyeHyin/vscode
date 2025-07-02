#include <bits/stdc++.h>
using namespace std;

struct Time {
    int hh, mm;
    Time(string s) {
        hh = stoi(s.substr(0, 2));
        mm = stoi(s.substr(3, 2));
    }
};

int toMinutes(Time t) { return t.hh * 60 + t.mm; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; ++i) {
        string start, end;
        cin >> start >> end;
        Time startTime(start), endTime(end);
        int startMin = toMinutes(startTime);
        int endMin = toMinutes(endTime);
        if (startMin <= endMin) {
            a.push_back({startMin, endMin});
        } else {
            a.push_back({startMin, 24 * 60 - 1});
            a.push_back({0, endMin});
        }
    }
    unordered_set<string> b;
    for (int i = 0; i < m; ++i) {
        string tea;
        cin >> tea;
        b.insert(tea);
    }

    vector<bool> isHappy(24 * 60, false);
    for (int j = 0; j < a.size(); j++) {
        for (int i = a[j].first; i <= a[j].second; i++) {
            isHappy[i % (24 * 60)] = true;
        }
    }

    int q;
    cin >> q;
    while (q--) {
        string ini, xqq, c, tea;
        cin >> ini >> xqq >> c >> tea;
        Time inii(ini), xqqq(xqq), cc(c);
        int iniMinutes = toMinutes(inii);
        bool happy = isHappy[iniMinutes];
        if (!(0 <= iniMinutes && iniMinutes <= 119) || !happy) {
            cout << "Loser xqq" << endl;
        } else if (toMinutes(xqqq) > toMinutes(cc) || b.find(tea) == b.end()) {
            cout << "Joker xqq" << endl;
        } else {
            cout << "Winner xqq" << endl;
        }
    }
    return 0;
}