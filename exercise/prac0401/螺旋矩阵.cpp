#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
    return a > b;
}
void calculateMN(int N, int &m, int &n){
    vector<int> possibleM, possibleN;

    for (m = 1; m <= N; m++){
        for (n = 1; n <= m; n++){
            if (m * n == N){
                possibleM.push_back(m);
                possibleN.push_back(n);
            }
        }
    }

    int minNum = 0x3fffffff, temp;
    bool haveChange = false;
    for (int i = 0; i < possibleM.size(); i++){
        temp = minNum;
        minNum = min(minNum, possibleM[i] - possibleN[i]);
        if (temp != minNum){
            haveChange = true;
        }
        if (haveChange){
            m = possibleM[i];
            n = possibleN[i];
        }
        haveChange = false;
    }
}
int main()
{
    int N, m, n;
    cin >> N;
    calculateMN(N, m, n);
    vector<int> number(N);
    for (int i = 0; i < N; i++){
        cin >> number[i];
    }
    sort(number.begin(), number.end(), cmp);
    // cout << m << " " << n << endl;
    vector<vector<int>> sout(m, vector<int>(n));
    int index = 0, x = 0, y = 0;
    while (m > 0 && n > 0){
        if (m == 1){
            for (int i = 0; i < n; i++) {
                sout[x][y] = number[index];
                y++;
                index++;
            }
            break;
        }
        else if (n == 1){
            for (int i = 0; i < m; i++){
                sout[x][y] = number[index];
                x++;
                index++;
            }
            break;
        }
        else{
            for (int i = 0; i < n - 1; i++){
                sout[x][y] = number[index];
                index++;
                y++;
            }
            for (int i = 0; i < m - 1; i++){
                sout[x][y] = number[index];
                index++;
                x++;
            }
            for (int i = 0; i < n - 1; i++){
                sout[x][y] = number[index];
                index++;
                y--;
            }
            for (int i = 0; i < m - 1; i++){
                sout[x][y] = number[index];
                index++;
                x--;
            }
            x++;
            y++;
        }
        m -= 2;
        n -= 2;
    }
    for (int i = 0; i < sout.size(); i++){
        for (int j = 0; j < sout[i].size(); j++){
            cout << sout[i][j];
            if (j != sout[i].size() - 1)
                cout << " ";
        }
        cout << endl;
    }
}
