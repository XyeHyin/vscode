#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt=0;
    for (int i = 0;i<n;i++) {
        for (int j =i+1;j<n;j++) {
                 int temp=a[i]*a[j];
                 if(sqrt(temp)*sqrt(temp)==temp){
                     cnt++;
                 }
            
        }
    }
    cout<<cnt<<endl;
        return 0;
}