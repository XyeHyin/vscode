#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<long double> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    long double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += num[i] * (n - i) * (i + 1);
    }
    printf("%.2llf", sum);
}