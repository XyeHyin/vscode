#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, target, rstleft, rstright;
    cin >> n >> target;
    vector<int> numbers(n);
    vector<int> beginning(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
        beginning[i] = numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    int left = 0, right = n - 1;
    while (left < right)
    {
        int sum = numbers[left] + numbers[right];
        if (sum == target)
        {
            rstleft = numbers[left];
            rstright = numbers[right];
            break;
                }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (beginning[i] == rstleft)
        {
            cout << "[" << i+1 << ",";
                break;
        }
    }
    for (int i = 0; i <n; i++)
    {
        if (beginning[i] == rstright)
        {
            cout << i+1 << "]";
            break;
        }
    }
}