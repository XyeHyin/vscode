#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, m;
    cin >> n >> m;
    priority_queue<ll> q;
    for (int i = 0; i < n; i++)
    {
        q.push(1);
    }
    ll cnt = 0;
    while (q.size() < m)
    {
        ll top = q.top();
        q.pop();
        if (top == 1)
        {
            cout << -1 << endl;
            return 0;
        }
        q.push(top / 2);
        q.push(top / 2);
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}