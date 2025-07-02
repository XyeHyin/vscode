#include <bits/stdc++.h>
using namespace std;
int main()
{
    int hh, mm;
    scanf("%2d:%2d", hh, mm);
    bool qiao = false;
    if (hh < 24 || hh > 12)
    {
        qiao = true;
    }
    else
    {
        printf("Only %2d:%2d.  Too early to Dang");
        return 0;
    }
    if (qiao)
    {
        if (mm > 0)
        {
            hh += 1;
        }
        hh -= 12;
        for (int i = 0; i < hh; i++)
        {
            cout << "Dang";
        }
    }
}