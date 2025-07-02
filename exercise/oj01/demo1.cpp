#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int b[100]={0}; 
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < n; j++)
        {
            if (a[i] == b[j])
            {
                flag = true;

            }
        }
        if (!flag)
        {
            b[i] = a[i];
        }
    }
        for (int i = 0; i < n; i++)
        {
            if (b[i] != 0)
            {
                cout << b[i] << " ";
            }
        }
    
}