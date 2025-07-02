#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n;j++){
          if(binary_search(a.begin()+j+1, a.end(), a[i] + a[j])) s.insert(a[i] + a[j]);
        }
    }
    cout << s.size() << endl;
    return 0;
}