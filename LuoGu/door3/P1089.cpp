#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> budget(12);
    for (int i = 1; i <= 12; i++) {
        cin >> budget[i];
    }
    int mom = 0, jin = 0;
    for (int i = 1; i <= 12; i++) {
        jin += 300;
        jin -= budget[i];
        if (jin < 0) {
            cout << -i << endl;
            return 0;
        }
            if (jin >= 100) {
                mom += jin / 100 * 100;
                jin -= jin / 100 * 100;
            }
    }
    cout << jin + mom * 1.2 << endl;
    return 0;
}