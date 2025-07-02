#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int bai = n / 100;
    int shi = n / 10 % 10;
    int ge = n % 10;
    for(int i=0;i<bai;i++)
    {
        cout << "B";
    }
    for(int i=0;i<shi;i++)
    {
        cout << "S";
    }
    for(int i=1;i<=ge;i++)
    {
        cout << i;
    }
    cout << endl;
}