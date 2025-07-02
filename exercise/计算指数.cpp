#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int ans = 2;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ans *=2;
        cout << ans << endl;
    }
    cout << "2^" << n << " = " << ans << endl;
}