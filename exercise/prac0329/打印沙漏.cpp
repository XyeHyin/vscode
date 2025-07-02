#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    char c;
    cin >> n >> c;
    int count = 1, cengShu = -1;
    int lose;
    while (2 * count * count - 1 <= n)
    {
        count++;
        cengShu += 2;
    }
    count--;
    lose = n - 2 * count * count + 1;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * (count - i) - 1; j++)
        {
            cout << c;
        }
        cout << endl;
    }
    for(int i = 1; i < count; i++)
    {
        for(int j = 0; j < count - i - 1; j++)
        {
            cout << " ";
        }
        for(int j = 0; j < 2 * i + 1; j++)
        {
            cout << c;
        }
        cout << endl;
    }
    cout << lose << endl;
}