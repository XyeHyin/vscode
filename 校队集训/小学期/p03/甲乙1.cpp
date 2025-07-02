#include <bits/stdc++.h>
using namespace std;
bool isprime(int n) {
    if (n == 0 || n == 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
// °´ºÍ²ð·Ö
int f1(int n) {
    int count = 0;
    int i = 2, j;
    for (; i <= n / 2; i++) {
        j = n - i;
        if (j <= 99 && i != j)
            count++;
    }
    return count;
}
int f2(int n) {
    int count = 0;
    int i = 2, j;
    int sq = sqrt(n);
    for (; i <= sq; i++) {
        if (n % i == 0) {
            j = n / i;
            if (j <= 99 && i != j)
                count++;
        }
    }
    return count;
}
/* void f1() {
    int i;
    for (i = 5; i <= 199; i += 2) {
        int j;
        for (j = 2; j <= i / 2; j++) {
            int k = i - j;
            if (k > 99)
                goto L;
            if (isprime(j) && isprime(k)) {
                goto L;
            }
        }
        cout << i << " ";
    L:;\
    }
} */
void f3() {
    int i, j, k;
    map<int, vector<int>> m;
    for (i = 5; i <= 197; i += 2) {
        for (j = 2; j <= i / 2; j++) {
            k = i - j;
            if (k <= 99 && k != j) {
                int count = f2(k * j);
                if (count == 1) {
                    goto L;
                }
            }
        }

        for (int u = 2; u <= i / 2; u++) {
            m[i].push_back((i - u) * u);
        }
    L:;
    }
    map<int, int> m1;
    for (auto it = m.begin(); it != m.end(); it++) {
        // cout << it->first << ": ";
        for (i = 0; i < it->second.size(); i++) {
            // cout << it->second[i] << " ";
            // cout << (it->second)[i] << " ";
            // cout << endl;
            m1[it->second[i]]++;
            // cout<<it->second[i]<<" ";
        }
        // cout << endl;
    }
    set<int> s;
    for (auto it = m1.begin(); it != m1.end(); it++) {
        if (it->second == 1)
            s.insert(it->first);
        // cout<<it->first<<" ";
    }
    int he, cheng;
    for (auto it = m.begin(); it != m.end(); it++) {
        int cnt = 0;
        vector<int> v;
        for (i = 0; i < it->second.size(); i++) {
            if (s.find(it->second[i]) != s.end()) {
                cnt++;
                v.push_back(it->second[i]);
            }
        }
        if (cnt == 1) {
            he = it->first;

            cheng = v[0];
        }
        v.clear();
    }
    for (int i = 2;i<=99;i++)
    {
        for (int j = 2; j <= 99;j++){
            if(i+j==he&&i*j==cheng)
            {
                cout<<i<<" "<<j<<endl;
                return;
            }
        }
    }
}

int main() {
    f3();
    return 0;
}