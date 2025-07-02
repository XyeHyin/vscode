#include <bits/stdc++.h>
using namespace std;
#define ll long long
string dictionary = "0123456789abcdefghijklmnopqrstuvwxyz";
ll toDecimal(string N, int radix)
{
    ll sum = 0;
    ll base = 1;
    for (int i = N.size() - 1; i >= 0; i--)
    {
        sum += base * dictionary.find(N[i]);
        base *= radix;
    }
    return sum;
}
ll binarySearch(string N, ll left, ll right, ll num1)
{
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        ll num2 = toDecimal(N, mid);
        if (num2 < 0 || num2 > num1)
            right = mid - 1;
        else if (num2 < num1)
            left = mid + 1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    string N1, N2;
    int tag, radix;
    cin >> N1 >> N2 >> tag >> radix;
    if (N1 == N2)
    {
        cout << radix << endl;
        return 0;
    }
    if (tag == 2)
        swap(N1, N2);
    long long num1 = toDecimal(N1, radix);
    char maxNum = *max_element(N2.begin(), N2.end());
    ll start = dictionary.find(maxNum) + 1;
    ll end = num1+1;
    ll ans = binarySearch(N2, start, end, num1);
    if (ans != -1)
        cout << ans << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}
