#include <bits/stdc++.h>
using namespace std;
int s[9];
const int fact[9] = {1,   1,   2,    6,    24,
                     120, 720, 5040, 40320};
const int dx[4] = {-1, 1, 0, 0};             
const int dy[4] = {0, 0, -1, 1};
const string dir = "UDLR"; 
int inverse_number() {
        int i, j, sum = 0;
        for (i = 1; i < 9; ++i)
            for (j = 0; j < i; ++j)
                if (s[j] != '9' && s[i] < s[j])
                    ++sum;
        return sum;
    }
int cantor() {
    int sum = 0;
    for (int i = 0; i < 9; ++i) {
        int cnt = 0;
        for (int j = i + 1; j < 9; ++j) {
            if (s[j] < s[i])
                ++cnt;
        }
        sum += cnt * fact[8 - i];
    }
    return sum;
}
void print() {
    for (int i = 0; i < 9; i++) {
        if (s[i] == 9)
            cout << "  ";
        else
            cout << s[i] << " ";
        if (i % 3 == 2)
            cout << endl;
    }
}
void bfs() {
    queue<pair<int, string>> q;
    unordered_map<int, bool> vis;
    int st = cantor();
    q.push({st, ""});
    vis[st] = true;

    while (!q.empty()) {
        auto [u, path] = q.front();
        q.pop();
        if (u == 0) {
            print();
            return;
        }

        int z = 0;
        while (s[z] != 0) ++z; 
        int x = z / 3, y = z % 3;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                swap(s[z], s[nx * 3 + ny]);
                int v = cantor();
                if (!vis[v]) {
                    q.push({v, path + dir[i]});
                    vis[v] = true;
                }
                swap(s[z], s[nx * 3 + ny]);
            }
        }
    }
}

int main() {
    srand(time(0));
    vector<char> dic = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < 9; i++) {
        int ra = rand() % dic.size();
        s[i]=dic[ra];
        dic.erase(dic.begin() + ra);
    }
    if(inverse_number()%2==1){
        print();
        cout<<"无解"<<endl;
    }
    bfs();                               
    return 0;
}