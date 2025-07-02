#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int arr[100005] = {0};
    for (int i = 0; i < 10; i++)
    {
        int n;
        cin >> n;
        arr[n]++;
    }
    vector<int> counts(arr, arr + 100005);
    sort(counts.begin(), counts.end(), cmp);
    int Count = counts[2];
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] ==  Count)
        {
            cout << i << endl;
            break;
        }
    }
}
