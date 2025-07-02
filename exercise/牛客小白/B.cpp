#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, min = 0x3f3f3f3f3;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < n; j++)
        {
            swap(a[j], b[j]);
            long long product = ((stoll(a) % 998244353) * (stoll(b) % 998244353)) % 998244353;
            if (min > product)
                min = product;
            else
                swap(a[j], b[j]);
        }
    }
    std::cout << min << endl;
    return 0;
}