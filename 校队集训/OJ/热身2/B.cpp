#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int index;
    cin >> index;
    nth_element(a.begin(), a.begin()+(n-index), a.end());
    cout<<a[n-index]<<endl;
    return 0;
}