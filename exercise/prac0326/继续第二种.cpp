#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    vector<int> nums(k);
    vector<bool> covered(300, false);
    for (int i = 0; i < k; i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < k; i++)
    {
        int num = nums[i];
        while (num != 1)
        {
            if (num % 2 == 0)
            {
                num = num / 2;
            }
            else
            {
                num = (3 * num + 1) / 2;
            }
            covered[num] = true;
        }
    }
    vector<int> keyNums;
    for (int i = 0; i < k; i++)
    {
        if (!covered[nums[i]])
        {
            keyNums.push_back(nums[i]);
        }
    }
    sort(keyNums.begin(), keyNums.end(), greater<int>());
    for (int i = 0; i < keyNums.size(); i++)
    {
        if (i != 0)
        {
            cout << " ";
        }
        cout << keyNums[i];
    }
}