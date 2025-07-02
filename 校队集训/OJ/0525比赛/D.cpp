#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> button(200);
int m, n;
map<vector<int>, int> step;

int bfs()
{
    vector<int> start(m, 0);
    queue<vector<int>> q;
    q.push(start);
    step[start] = 0;
    while (!q.empty())
    {
        vector<int> cur = q.front();
        q.pop();
        if (count(cur.begin(), cur.end(), 0) == 0)
            return step[cur];
        for (int i = 0; i < n; i++)
        {
            vector<int> next = cur;
            for (int j : button[i])
            {
                next[j] = next[j] == 0 ? 1 : 0;
            }
            if (!step.count(next))
            {
                step[next] = step[cur] + 1;
                q.push(next);
            }
        }
    }
    return -1;
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        button[i].resize(k);
        for (int j = 0; j < k; j++)
            cin >> button[i][j];
    }
    cout << bfs() << endl;
}