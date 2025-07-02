#include <bits/stdc++.h>
using namespace std;
#define int long long

void sorter(vector<int> &a, int l, int r)
{
    if (l == r)return;
    int mid = (l + r) / 2;
    vector<int> temp(r - l + 1);
    int idx = 0;
    for (int i = l; i <= r; i += 2) temp[idx++] = a[i];
    for (int i = l + 1; i <= r; i += 2) temp[idx++] = a[i];
    for (int i = l; i <= r; i++)a[i] = temp[i - l];
    sorter(a, l, mid);
    sorter(a, mid + 1, r);
}

signed main()
{
    int n, m;
    cin >> n >> m;
    int palu = pow(2, n);
    vector<int> a(palu);
    for (int i = 0; i < palu; i++)a[i] = i;
    sorter(a, 0, palu - 1);
    for (int i = 0; i < m; i++){
        int x;
        cin >> x;
        cout << a[x] << endl;
    }
}
