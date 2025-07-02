#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int father[N], isRoot[N] = {0}, course[N] = {0}, cnt[N] = {0};

int findFather(int x)
{   
    int a = x;
    while (x != father[x])
    {
        x = father[x];
    }
    while(a != father[a])
    {
        int z = a;
        a = father[a];
        father[z] = a;
    }
}

void Union(int a, int b)
{
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB)
    {
        father[faA] = faB;
    }
}

int main()
{
    int n, k, h;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        father[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        getchar();
        for (int j = 0; j < k; j++)
        {
            cin >> h;
            if (course[h] == 0)
            {
                course[h] = i;
            }
            Union(i, findFather(course[h]));
        }
    }
    for (int i = 1; i <= n; i++)
    {
        isRoot[findFather(i)]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (isRoot[i] != 0)
        {
            ans++;
        }
    }
    cout << ans << endl;
    sort(isRoot + 1, isRoot + n + 1, greater<int>());
    for (int i = 1; i <= ans; i++)
    {
        cout << isRoot[i];
        if (i < ans)
        {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}