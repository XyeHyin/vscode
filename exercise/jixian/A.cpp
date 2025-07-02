#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;
    string s = bitset<32>(x).to_string();
    s.erase(0, s.find_first_not_of('0'));
    cout << s << endl;
    cout << oct << x << endl;
    cout << hex << x << endl;
    return 0;
}