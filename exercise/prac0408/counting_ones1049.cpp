#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    int count = 0;
    cin >> n;
    vector<int> arr;
    while (n != 0) {
        arr.push_back(n % 10);
        n /= 10;
    }
    for (int i = arr.size() - 1; i >= 0; i++) {
        int left = 0, right = 0, t = 1;
        for (int j = arr.size() - 1; j > i; j--) {
            left = left * 10 + arr[j];
        }
        for (int j = i - 1; j >= 0; j--) {
            right = right * 10 + arr[j];
            t *= 10;
        }
        count += left * t;
        if (arr[i] == 1)
            count += right + 1;
        else if (arr[i] > 1)
            count += t;
    }
    cout << count << endl;
}