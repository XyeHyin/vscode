#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        for (int i = 1; i <= sqrt(a); i++) {
            for (int j = i; j <= sqrt(a); j++) {
                if (i * i + j * j == a) {
                    cout << "Yes" << endl;
                    goto out;
                }
                if(i * i + j * j > a){
                    break;
                }
            }
        }
    no:;
        cout << "No" << endl;
        
    out:;
    }
    return 0;
}