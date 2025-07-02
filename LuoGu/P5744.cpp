#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        string s;
        int a, b;
        cin >> s >> a >> b;
        b *= 1.2;
        if(b>600)b = 600;
        cout<<s<<" "<<++a<<" "<<b<<endl;
    }
}