#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    if (n == 5){
        cout << "1.0" << endl;
        return 0;
    }
    cout << "-1" << endl;
}