#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int j = 0;  
    do {
        if (j == k) {
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            break;
        }
        j++;
    } while (next_permutation(arr.begin(), arr.end()));
    return 0;
}