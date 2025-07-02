#include <bits/stdc++.h>
using namespace std;
struct product
{
    string s;
    int n;
} a[15];

bool cmp(product a, product b)
{
    return a.n > b.n;
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i].s >> a[i].n;
    }
    sort(a, a + 10, cmp);
    for (int i = 0; i < 3; i++)
    {
        cout << a[i].s << " ";
    }
    cout << endl;
}