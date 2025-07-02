#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct student
{
    ll s;
    int shiji;
    int kaoshi;
} a[1005];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].s;
        cin >> a[i].shiji >> a[i].kaoshi;
    }
    int m;
    cin >> m;
    int num;
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        for (int j = 0; j < n; j++)
        {
            if (num == a[j].shiji)
                cout << a[j].s << " " << a[j].kaoshi << endl;
            break;
        }
    }
}