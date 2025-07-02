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
int main(){
    int n;
    cin >> n;
    Euler(n+1);
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (!not_prime[i]) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}