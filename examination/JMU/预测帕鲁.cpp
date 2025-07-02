#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> paluu(N);
    for (int i = 0; i < N; i++)
    {
        cin >> paluu[i];
    }
    int a, b;
    cin >> a >> b;
    int sum = (paluu[a - 1] + paluu[b - 1]+0.9999999)/ 2; 
    int min = 0x3f3f3f3f, pos = -1;
    for (int i = 0; i < N; i++)
    {
        int diff = abs(paluu[i] - sum);
        if (diff < min || (diff == min && pos == -1))
        {
            min = diff;
            pos = i;
        }
    }
    cout << pos + 1<<endl;
}