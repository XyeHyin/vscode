#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> card;
    int n;
    cin >> n;
    card.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int n1;
        cin >> n1;
        card.push_back(n1);
    }
    vector<int> ans(n);
    for (int i = 1; i <= n; i++)
    {
        ans[abs(card[i] - (i + 1))]++;
    }
    for (int i = ans.size(); i >= 0; i--)
    {
        if (ans[i] > 1)
        {
            cout << i << " " << ans[i] << endl;
        }
    }
}