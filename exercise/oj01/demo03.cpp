#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    cin >> num;
    int a = num / 100;     
    int b = num / 10 % 10; 
    int c = num % 10;      
    if (pow(a, 3) + pow(b, 3) + pow(c, 3) == num)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}