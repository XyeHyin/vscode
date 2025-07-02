#include <bits/stdc++.h>
using namespace std;
int solution(int n, std::vector<int> u) {
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[u[i]]++;
    }
    int tmp=m.begin()->second;
    return n-tmp;
}

int main() {
    cout << solution(17, {6, 7, 3, 12, 13, 16, 15, 4, 4, 15, 10, 5, 5, 17, 8, 3, 11})<< endl;
}