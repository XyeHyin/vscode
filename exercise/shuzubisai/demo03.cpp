#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, target;
    cin >> N >> target;
    vector<int> apples(N);
    for (int i = 0; i < N; i++)
    {
        cin >> apples[i];
    }

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = i; j < N ; j++)
        {
            sum += apples[j];
            if (sum == target)
            {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}