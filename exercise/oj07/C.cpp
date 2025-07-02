#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;
    int sum = fib[1];
    for (int i = 2; i <= n; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
        sum += fib[i];
    }
    cout << sum << endl;
    return 0;
}