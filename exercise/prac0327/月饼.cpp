#include <bits/stdc++.h>
using namespace std;
struct Mooncake
{
    double store;
    double sell;
    double onePrice;
};
bool cmp(Mooncake a, Mooncake b)
{
    return a.onePrice > b.onePrice;
}
int main()
{
    int n, need;
    double selling=0;
    cin >> n >> need;
    vector<Mooncake> mooncake(n);
    for (int i = 0; i < n; i++)
    {
        cin >> mooncake[i].store;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> mooncake[i].sell;
        mooncake[i].onePrice = mooncake[i].sell / mooncake[i].store;
    }
    sort(mooncake.begin(), mooncake.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        if (mooncake[i].store<= need)
        {
            selling += mooncake[i].sell;
            need -= mooncake[i].store;
            mooncake[i].store = 0;
        }else{
            selling += mooncake[i].sell * (need / mooncake[i].store);
            mooncake[i].store -= need;
            break;
        }
    }
    printf("%.2f", selling);
    
}