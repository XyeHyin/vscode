#include <bits/stdc++.h>
using namespace std;

int x, y, target;
bool visited[101][101];

bool dfs(int a, int b)
{
    if (visited[a][b])
        return false;
    visited[a][b] = true;
    if (a == target || b == target || a + b == target)
        return true;
    return dfs(x, b) ||                                 
           dfs(a, y) ||                                 
           dfs(0, b) ||                                 
           dfs(a, 0) ||                                 
           dfs(a - min(a, y - b), b + min(a, y - b)) || 
           dfs(a + min(b, x - a), b - min(b, x - a));  
}

int main()
{
    cin >> x >> y >> target;
    if (dfs(0, 0))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}