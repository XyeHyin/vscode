#include <bits/stdc++.h>
using namespace std;
const int maxN = 10010;
int father[maxN], bird[maxN];
int findFather(int x) {
    return father[x] = (x == father[x] ? x : father[x] = findFather(father[x]));
}
void merge(int x, int y) {
    int fx = findFather(x);
    int fy = findFather(y);
    if (fx != fy)
        father[fx] = fy;
}
int main() {
    int P, Q, N;
    cin >> P;
    for (int i = 1; i <= P; i++) {
        father[i] = i;
    }
    int cntBird = 0;
    for (int i = 1; i <= P; i++) {
        cin >> N;
        for (int j = 0; j < N; j++) {
            int indices;
            cin >> indices;
            if (bird[indices] == 0) {
                bird[indices] = i;
                cntBird++;
            }
            if (bird[indices] != 1) {
                merge(i, bird[indices]);
            }
        }
    }
    int cntTree = 0;
    for (int i = 1; i <= cntBird; i++) {
        if (father[i] == i) {
            cntTree++;
        }
    }
    cout << cntTree << " " << cntBird << endl;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int bird1 = 0, bird2 = 0;
        cin >> bird1 >> bird2;
        if (findFather(bird1) == findFather(bird2)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}