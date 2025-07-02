#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(N + M + 1);
    int x, i;
    int sum = 0;
    for (i = 0; i < N + M + 1; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    if (!M) {
        for (i = 0; i < N + M + 1; i++)
            sum += a[i];
    } else if (a[0] >= 0) {
        sum -= a[0];
        for (i = 1; i < N + M + 1; i++)
            sum += a[i];
    } else {
        for (i = 0; i < N + M + 1; i++)
            sum += abs(a[i]);
        if (a[N + M] < 0)
            sum += 2 * a[N + M];
    }
    cout << sum << endl;

    return 0;
}