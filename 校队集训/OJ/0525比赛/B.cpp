#include <bits/stdc++.h>
using namespace std;
struct node{
    string time;
    int u, I;
};
int main(){
    int n;
    cin >> n;
    vector<node> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i].time >> nodes[i].u >> nodes[i].I;
    int total = 0;
    for (int i = 1; i < n; i++){
        int t = stoi(nodes[i].time.substr(0, 2)) * 3600 + stoi(nodes[i].time.substr(3, 2)) * 60 + stoi(nodes[i].time.substr(6, 2)) - stoi(nodes[i - 1].time.substr(0, 2)) * 3600 - stoi(nodes[i - 1].time.substr(3, 2)) * 60 - stoi(nodes[i - 1].time.substr(6, 2));
        total += t * nodes[i - 1].u * nodes[i - 1].I;
    }
    cout << total;
}