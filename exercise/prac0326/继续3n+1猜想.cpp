#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int k;
    cin >> k;
    vector<int> guanjianshuzi;
    vector<int> nums(k);
    vector<int> nums2(k);
    for (int i = 0; i < k; i++)
    {
        cin >> nums[i];
        nums2[i] = nums[i];
    }
    for (int i = 0; i < k; i++)
    {
        while (nums2[i] != 1)
        {
            if (nums2[i] % 2 == 0)
            {
                nums2[i] = nums2[i] / 2;
                for (int j = 0; j < k; j++)
                {
                    if (nums2[i] == nums2[j] && i != j && nums2[i] != 1 && nums2[j] != 1)
                    {
                        bool flag = true;
                        for (int l = 0; l < guanjianshuzi.size(); l++)
                        {
                            if (guanjianshuzi[l] == nums[i])
                            {
                                flag = false;
                                break;
                            }
                        }
                        if (flag)
                        {
                            guanjianshuzi.push_back(nums[i]);
                        }
                    }
                }
            }
            else
            {
                nums2[i] = (3 * nums2[i] + 1) / 2;
                for (int j = 0; j < k; j++)
                {
                    if (nums2[i] == nums2[j] && i != j && nums2[i] != 1 && nums2[j] != 1)
                    {
                        bool flag = true;
                        for (int l = 0; l < guanjianshuzi.size(); l++)
                        {
                            if (guanjianshuzi[l] == nums[i])
                            {
                                flag = false;
                                break;
                            }
                        }
                        if (flag)
                        {
                            guanjianshuzi.push_back(nums[i]);
                        }
                    }
                }
            }
            for (int j = 0; j < guanjianshuzi.size(); j++)
            {
                if (nums2[i] == guanjianshuzi[j])
                {
                    guanjianshuzi.erase(guanjianshuzi.begin() + j);
                    break;
                }
            }
        }
    }
    sort(guanjianshuzi.begin(), guanjianshuzi.end(), cmp);
    for (int i = 0; i < guanjianshuzi.size(); i++)
    {
        if (i == guanjianshuzi.size() - 1)
        {
            cout << guanjianshuzi[i];
        }
        else
        {
            cout << guanjianshuzi[i] << " ";
        }
    }
}