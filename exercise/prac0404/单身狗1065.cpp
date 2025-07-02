#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M;
    cin >> N;
    map<int, int> lovers;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        lovers[a] = b;
        lovers[b] = a;
    }
    cin >> M;
    vector<int> guests(M);
    set<int> singleDogs;
    for (int i = 0; i < M; i++)
    {
        cin >> guests[i];
    }
    for (int i = 0; i < M; i++)
    {
        if (lovers.count(guests[i]) == 0 || find(guests.begin(), guests.end(), lovers[guests[i]]) == guests.end())
        {
            singleDogs.insert(guests[i]);
        }
    }
    cout << singleDogs.size() << endl;
    for (auto it = singleDogs.begin(); it != singleDogs.end(); it++)
    {
        if (it != singleDogs.begin())
        {
            cout << " ";
        }
        printf("%05d", *it);
    }
    return 0;
}