#include <bits/stdc++.h>
#include <iomanip> 
using namespace std;
int main()
{
    int mm, dd, yyyy;
    char dash;
    cin >> mm >> dash>> dd >> dash>> yyyy;
    printf("%04d-%02d-%02d", yyyy, mm, dd);
}