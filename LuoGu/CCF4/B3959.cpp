#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    int j = 1;
    for(int i=0;i<n;i++){
       if(a[i]>=j){
           j++;
       }
    }
    cout << j-1 << endl;
    return 0;
}