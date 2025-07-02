#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[9];
    int meilingshu;
    bool haveZero = false;
    for (int i = 0; i < 9; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == 0)
        {
            haveZero = true;
        }
        if (ans[i] != 0)
        {
            meilingshu = i;
            break;
        }
    }
    if (haveZero)
    {
        swap(ans[0], ans[meilingshu]);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }
}