#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, k;
bool isprime(int x)
{     if(x==1||x==0)return false;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)return false;
    }
    return true;
}
int main()
{
    cin >> n >> k;
    string s;
    cin >> s;
    int pos = k-1;
    for (int i = k-1; i < n; i++)
    {
        if (isprime(stoi(s.substr(pos, k))))
        {
            cout << s.substr(pos, k) << endl;
            return 0;
        }
        pos++;
    }
    cout << "404" << endl;
}