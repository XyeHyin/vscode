#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> res;
    while (n != 0 && m != 0)
    {
        int x = (m + n - 1) / n;
        res.push_back(x);
        int temp = m;
        m = n * x - m;
        n = temp;
    }
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i] << "\n";

    return 0;
}