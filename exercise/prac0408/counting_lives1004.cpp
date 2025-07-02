#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
vector<int> children[MAXN];
int levelCount[MAXN];

void bfs()
{
    queue<pair<int, int>> q;
    q.push({1, 0});
    while (!q.empty())
    {
        int node = q.front().first;
        int level = q.front().second;
        q.pop();
        if (children[node].empty())
        {
            levelCount[level]++;
        }
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
    
    int flg = 0;
    for (int i = 0; i < N;i++){
        if(levelCount[i]!=0){
            flg = i;
            break;
        }
    }
        for (int j = 0; j < N; j++)
        {   if(levelCount[j]==0&&j>flg){
                break;
        }
            if (j > 0) cout << " ";
            cout << levelCount[j];
        }
    cout << endl;
    
    return 0;

}