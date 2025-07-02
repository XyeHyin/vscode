#include <bits/stdc++.h>
using namespace std;


int main()
{
    string a, b;
    cin >> a >> b;
    string result = "";
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry > 0)
    {
        if (i >= 0)
            carry += a[i] -'0';
             i--;
        if (j >= 0)
            carry += b[j] -'0' ;
                j--;
        result = char(carry % 2 + '0') + result;
        carry /= 2;
    }
    cout << result << endl;
    return 0;
}