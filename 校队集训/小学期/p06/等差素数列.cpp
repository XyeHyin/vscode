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
vector<int> shulie; int cha;
int dfs(int n){
    
    return 0;
}
int main() {
    Euler(1000);

    return 0;
}