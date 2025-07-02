#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int count = 0;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int j = n - 1; j > 0; j--)
    {
        for (int i = 0; i < j; i++)
        {
            if (arr[i] > 0 && arr[j] > 0)
            {
                count += (arr[j] - arr[i]) * (arr[j] - arr[i]);
            }
            else if (arr[i] < 0 && arr[j] > 0)
            {
                count += (arr[j] + arr[i]) * (arr[j] + arr[i]);
            }
            else if (arr[i] < 0 && arr[j] < 0)
            {
                count += (arr[j] + arr[i]) * (arr[j] + arr[i]);
            }
            else if (arr[i] > 0 && arr[j] < 0)
            {
                count += (arr[j] + arr[i]) * (arr[j] + arr[i]);
            }
        }
    }
    cout << count;
}