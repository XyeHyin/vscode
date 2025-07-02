#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a;
    int num;
    int flag = 0;
    while (true) {
        if(a.size()>=n*n)break;
        cin >> num;
        for (int i = 0; i < num;i++){
            a.push_back(flag);
        }
        flag = !flag;
    };
    for (int i = 0; i < n * n;i++){
        cout << a[i];
        if((i+1)%n==0)
            cout << endl;
    }
        return 0;
}