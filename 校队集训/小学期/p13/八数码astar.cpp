#include <bits/stdc++.h>
using namespace std;
vector<int> dic = {1, 2, 3, 4, 5, 6, 7, 8, 9};
vector<int> a;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
struct node {
    vector<vector<int>> a;
    vector<vector<int>> father;
};
int jiecheng(int n) {
    if (n == 1 || n == 0)
        return 1;
    return n * jiecheng(n - 1);
}
void print() {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 9) cout << "  ";
        else cout << a[i] << " ";
        if (i % 3 == 2) cout << endl;
    }
}
int manhattan() {
    int i, sum = 0;
    for (int i = 0; i < 9; ++i)
        if (a[i] != 9) {
            sum += abs(i / 3 - (a[i] - 1) / 3) + abs(i % 3 - (a[i] - 1) % 3);
        }
    return sum;
}
int kangtuo() {
    int n = 0;
    for (int i = 0; i < a.size(); i++) {
        n += (a[i] - i - 1) * jiecheng(a.size() - i - 1);
    }
    return n;
}
void bfs() {
    vector<vector<int>> ans(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ans[i][j] = a[i * 3 + j];
        }
    }

    int x = 0, y = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (ans[i][j] == 9) {
                x = i;
                y = j;
            }
        }
    }

    while (kangtuo() != 0) {
        bool flag = false;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                if (ans[x][y] > ans[nx][ny]) {
                    swap(ans[x][y], ans[nx][ny]);
                    x = nx;
                    y = ny;
                }
            }
        }
    }
}
// int minn=0x3f3f3f3f,minx,miny;
// bool flag = false;
// for (int i = 0; i < 4;i++){
//     int x = 0, y = 0;
//     for (int j = 0; j < 3;j++){
//         for (int k = 0; k < 3;k++){
//             if (ans[j][k] == 9){
//                 x = j;
//                 y = k;
//             }
//         }
//     }
//     int nx = x + dx[i];
//     int ny = y + dy[i];
//     if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3){
//         if(minn>ans[nx][ny]){
//             minn = ans[nx][ny];
//             minx = nx;
//             miny = ny;
//             flag = true;
//         }
//     }

// }
//     if(flag){
//         swap(ans[x][y], ans[minx][miny]);
//         flag = false;
//     }
//}
int main() {
    srand(time(0));
    for (int i = 0; i < 9; i++) {
        int ra = rand() % dic.size();
        a.push_back(dic[ra]);
        dic.erase(dic.begin() + ra);
    }
    // for(int i=1;i<=9;i++){
    //     a.push_back(i);
    // }
    print();
    cout << kangtuo() << endl;
    bfs();
    return 0;
}