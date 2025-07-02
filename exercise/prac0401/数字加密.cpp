#include <bits/stdc++.h>
using namespace std;

int main()
{
    char dictionary[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};
    string a, b;
    cin >> a >> b;
    bool isOu = false;
    char ans[100];
    int check = 0;
    if(b.size()>a.size()){
        a.insert(0, b.size() - a.size(), '0');
    }else if(b.size()<a.size()){
        b.insert(0, a.size() - b.size(), '0');
    }

    for (int i = b.size() - 1; i >= 0; i--)
    {
        if (isOu)
        {
            check = (b[i] - '0') - (a[i] - '0');
            if (check < 0)
                ans[i] = dictionary[check + 10];
            else
                ans[i] = dictionary[check];
            isOu = false;
        }
        else
        {
            ans[i] = dictionary[((a[i] - '0') + (b[i] - '0')) % 13];
            isOu = true;
        }
    }
    for (int i = 0; i <b.size(); i++)
    {
        cout << ans[i];
    }
}