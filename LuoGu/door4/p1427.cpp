#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a;
    while (true){
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        a.push_back(n);
    }
    for (int i = a.size() - 1; i >= 0; i--) {
        cout << a[i] << " ";
    }
    return 0;
}