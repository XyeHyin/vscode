#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n;
    vector<int> num1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num1[i];
    }
    cin >> m;
    vector<int> num2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> num2[i];
    }
    vector<int> num3;
    num3.insert(num3.end(), num1.begin(), num1.end());
    num3.insert(num3.end(), num2.begin(), num2.end());
    sort(num3.begin(), num3.end());
    for (int i = 0; i < num3.size(); i++)
    {
        cout << num3[i] << " ";
    }
}