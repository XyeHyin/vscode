#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[10], count;
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 10; i++)
    {
        if (a[i] % 2 == 0)
        {
            ++count;
        }
        if (count == 2)
        {
            cout << i;
            break;
        }
    }
}