#include <bits/stdc++.h>
using namespace std;
int main(){
    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    vector<int> a(100, 0);
    for (int i = 1; i <= s1; i++) {
        for (int j = 1; j <= s2; j++) {
            for (int k = 1; k <= s3; k++) {
                a[i + j + k]++;
            }
        }
    }
    int max = max_element(a.begin(), a.end()) - a.begin();
    cout << max << endl;
    return 0;
}