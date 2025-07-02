#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, p;
    cin >> n >> p;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long ans = 0, left = 0, right =0;
    while (right<n)
    {    
        if (a[right] <= a[left] * p)
        {
            ans = max(ans, right - left + 1);
            right++;
        }else{
            left++;
        }
    }
    cout << ans;
}