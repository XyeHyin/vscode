#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    if((s[6]-'0')>=0&&(s[6]-'0')<=9){
    if ((s[6] - '0') % 2 == 0)
    {
        cout << "even" << endl;
    }
    else {
        cout << "odd" << endl;
    }
    }
    else{
        cout << "bad" << endl;
    }
}