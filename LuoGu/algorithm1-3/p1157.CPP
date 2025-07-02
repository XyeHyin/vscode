#include <bits/stdc++.h>
using namespace std;
vector<int> c;
void f(int num,int k ,int n) {
    if (c.size() == k) {
            for(int i=0;i<c.size();i++){
                cout << setw(3)<<c[i];
            }
            cout << endl;
            return;
    }
    if (num > n) return;
    c.push_back(num);
    f(num + 1, k,n);
    c.pop_back();
    f(num + 1, k,n);
}
int main(){
    int n,r;
    cin >> n >> r;
    f(1, r, n);
    return 0;
}