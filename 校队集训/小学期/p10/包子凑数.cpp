#include <bits/stdc++.h>
using namespace std;
bool not_prime[10000001] = {true, true};
vector<int> prime;
void Euler(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!not_prime[i]) {
            prime.push_back(i);
        }
        for (int pri_j : prime) {
            if (i * pri_j > n)
                break;
            not_prime[i * pri_j] = true;
            if (i % pri_j == 0) {
                break;
            }
        }
    }
}

vector<int> legal;
void illegel(int n) {
    for (int i = 2; i <= n; i++) {
        if()
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int cnt = a[0] - 1;
    bool isou = true;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            isou = false;
            break;
        }
    }
    if (isou) {
        cout << "INF" << endl;
    }
    return 0;
}