#include <bits/stdc++.h>
using namespace std;
int f(int n) {
    if (n <= 3) return 1 ;
    int heap = n / 3;
    int worst = 0x3f3f3f3f;
    for (int i = heap; i < heap + 2; ++i) {
        int peiping = n - 2 * i;
        worst = min(worst, 1 + max(f(i), f(peiping)));
    }

    return worst;
}

int main() {
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    int bad = (rand()%n)+1;
    a[bad] = 1;
    cout<<f(n)<<endl;

    return 0;
}