#include <bits/stdc++.h>
using namespace std;

bool isDamei(int n, vector<int> &factors, int start, int count, int sum)
{
    if (count == 4)
    {
        return sum % n == 0;
    }
    for (int i = start; i < factors.size(); i++)
    {
        if (isDamei(n, factors, i + 1, count + 1, sum + factors[i]))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n;
        vector<int> factors;
        for (int j = 1; j * j <= n; j++)
        {
            if (n % j == 0)
            {
                factors.push_back(j);
                if (j * j != n)
                {
                    factors.push_back(n / j);
                }
            }
        }
        if (factors.size() < 4)
        {
            cout << "No" << endl;
            continue;
        }
        if (isDamei(n, factors, 0, 0, 0))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}