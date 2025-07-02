#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, C;
    cin >> N >> C;
    vector<int> a(N);
    for (int i = 0;i<N;i++){
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 0;i<N;i++){
        for (int j = 0; j < N;j++){
            if(i-j==C)
                cnt++;
        }
    }
    cout<<cnt;
        return 0;
}