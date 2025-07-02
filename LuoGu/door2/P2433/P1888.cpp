#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> tri = {a, b, c};
    sort(tri.begin(), tri.end());
    cout << tri[0] / gcd(tri[0], tri[2]) << "/" << tri[2] / gcd(tri[0], tri[2]) << endl;
    return 0;
}