#include <bits/stdc++.h>
using namespace std;
// 偶数等于素数+素数,甲一定不是素数
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
int main() {
    set<int> jia, yi;
    for (int i = 2; i <= 99; i++) {
        for (int j = 2; j <= 99; j++) {
            jia.insert(i + j);
            if (!not_prime[i * j]) {
                yi.insert(i * j);
            }
        }
    }
    for (auto i = jia.begin(); i != jia.end(); i++) {
        if (*i % 2 == 0) {
            jia.erase(i);
        }
    }
    for (auto i = yi.begin(); i != yi.end(); i++) {
        int cnt = 0;
        for (int j = 2; j <= 99; j++) {
            for (int k = j; k <= 99; k++) {
                if (*i == j * k) {
                    cnt++;
                }
            }
        }
        if (cnt != 2) {
            yi.erase(i);
        }
    }

    for (auto i = jia.begin(); i != jia.end(); i++) {
        bool flag = false;
        for (int j = 2; j <= 99; j++) {
            for (int k = 2; k <= 99; k++) {
                if (j + k == *i) {
                    if (yi.find(j * k) != yi.end()) {
                        flag = true;
                        break;
                    }
                }
                if(k>*i) break;
            }
            if(j>*i) break;
        }
        if (!flag) {
            jia.erase(i);
        }
    }
    for( auto i=yi.begin();i!=yi.end();i++){
        bool flag=false;
        for (int j = 2; j <= *i;j++){
            for (int k = 2;k<=*i;k++){
                if(j*k==*i){
                    if(jia.find(j+k)!=jia.end()){
                        flag=true;
                        break;
                    }
                }
            }
        }
        if(!flag){
            yi.erase(i);
        }
    }
    for (auto i = jia.begin(); i != jia.end(); i++) {
        cout << *i << " ";
    }
    // for (auto i = yi.begin(); i != yi.end(); i++) {
    //     cout << *i << " ";
    // }
    return 0;
}