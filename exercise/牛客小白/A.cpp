#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n, a, k;
        cin >> n >> a >> k;
        a ++;
        for (int j = 0; j < k; j++){
            if (to_string(a).find('7') != string::npos || a % 7 == 0){
                cout << 'p' << " ";
            }
            else{
                cout << a << " ";
            }
            a += n;
        }
        cout << endl;
    }
}