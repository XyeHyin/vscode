#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
vector<int> children[MAXN];
int levelCount[MAXN]={0};

void bfs()
{
    queue<pair<int, int>> q;
    q.push({1, 1});
    while (!q.empty())
    {
        int node = q.front().first;
        int level = q.front().second;
        q.pop();
        levelCount[level]++;
        for (int child : children[node])
        {
            q.push({child, level + 1});
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int id, K;
        cin >> id >> K;
        for (int j = 0; j < K; j++)
        {
            int child;
            cin >> child;
            children[id].push_back(child);
        }
    }
    bfs();
    int maxnum = 0, maxi = 1;
    for (int i = 1; i <= N; i++)
    {
        if (levelCount[i] > maxnum)
        {
            maxnum = levelCount[i];
            maxi = i;
        }
    }
    cout << maxnum << " " << maxi << endl;

    return 0;
}