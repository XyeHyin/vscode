#include <bits/stdc++.h>
using namespace std;
int solution(int distance, int n,
                     std::vector<std::vector<int>> gasStations) {
    for (int i = 0; i < n; i++) {
        gasStations[i][0] = distance - gasStations[i][0];
    }
    sort(gasStations.begin(), gasStations.end(),
         [](vector<int> a, vector<int> b) { return a[0] < b[0]; });

    int cur = 0;
    int oil = 200;
    int money = 0;
    int ans = 0;
    int j = 0;
    int minn = 0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
        if (gasStations[i][0] <= 200) {
            if (gasStations[i][1] < minn) {
                minn = gasStations[i][1];
                j = i;
            }
        }
    }
    if (minn == 0x3f3f3f3f) {
        return -1;
    }
    oil -= gasStations[j][0];
    cur = gasStations[j][0];
    money = gasStations[j][1];
    while (true) {
        int minn = 0x3f3f3f3f;
        for (int i = j + 1; i < n; i++) {
            if (gasStations[i][0] <= cur + 400) {
                if (gasStations[i][1] < minn) {
                    minn = gasStations[i][1];
                    j = i;
                }
            }
        }
        if (minn == 0x3f3f3f3f) {
            return -1;
        }
        if (gasStations[j][1] > money) {
            if (cur + 200 >= distance) {
                ans += money * (distance - cur+200);
                return ans;
            } else {
                ans += money * (400 - oil);
                oil = 400;
                cur = gasStations[j][0];
                money = gasStations[j][1];
                if(j==n-1){
                ans += money * (distance - cur+200);
                return ans;
                }
            }
        } else {
            ans += money * (gasStations[j][0] - cur);
            oil = gasStations[j][0] - cur;
            cur = gasStations[j][0];
            money = gasStations[j][1];
            if(j==n-1){
            ans += money * (distance - cur+200);
            return ans;
        }
        }
        
    }
    return ans;
}

int main() {
    std::vector<std::vector<int>> gasStations1 = {
        {100, 1}, {200, 30}, {400, 40}, {300, 20}};
    std::vector<std::vector<int>> gasStations2 = {
        {100, 999},  {150, 888},  {200, 777}, {300, 999},
        {400, 1009}, {450, 1019}, {500, 1399}};
    std::vector<std::vector<int>> gasStations3 = {{101}, {100, 100}, {102, 1}};
    std::vector<std::vector<int>> gasStations4 = {
        {34, 1},     {105, 9},  {9, 10},    {134, 66}, {215, 90},
        {999, 1999}, {49, 0},   {10, 1999}, {200, 2},  {300, 500},
        {12, 34},    {1, 23},   {46, 20},   {80, 12},  {1, 1999},
        {90, 33},    {101, 23}, {34, 88},   {103, 0},  {1, 1}};

    std::cout << (solution(500, 4, gasStations1) == 4300) << std::endl;
    std::cout << (solution(500, 7, gasStations2) == 410700) << std::endl;
    std::cout << (solution(500, 3, gasStations3) == -1) << std::endl;
    std::cout << (solution(100, 20, gasStations4) == 0) << std::endl;
    std::cout << (solution(100, 0, std::vector<std::vector<int>>{}) == -1)
              << std::endl;

    return 0;
}