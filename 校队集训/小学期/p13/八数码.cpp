#include <bits/stdc++.h>
using namespace std;
vector<char> dic = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
vector<char> a;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
struct node {
    vector<vector<int>> a;
    vector<vector<int>> father;
};
int jiecheng[]={1,1,2,6,24,120,720,5040,40320,362880};
void print() {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 9)
            cout << "  ";
        else
            cout << a[i] << " ";
        if (i % 3 == 2)
            cout << endl;
    }
}
int kangtuo() {
    int n = 0;
    for (int i = 0; i < a.size(); i++) {
        n += (a[i] - i - 1) * jiecheng[a.size() - i - 1];
    }
    return n;
}
void bfs() {
    if(a==dic){
        print();
    }
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

}
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